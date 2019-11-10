#include <cassert>
#include <condition_variable>
#include <cstdint>
#include <cstring>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

const int kURLNum = 5;

std::string urls[kURLNum] = {
    std::string("http://news.yahoo.com"),
    std::string("http://news.yahoo.com/news"),
    std::string("http://news.yahoo.com/news/topics/"),
    std::string("http://news.google.com"),
    std::string("http://news.yahoo.com/us"),
};
int edges[kURLNum][kURLNum];
// std::unordered_map<int, int> edges;

class HtmlParser {
 public:
  std::vector<std::string> getUrls(const std::string& url) {
    std::vector<std::string> res;
    for (int i = 0; i < kURLNum; ++i) {
      if (urls[i] != url) {
        continue;
      }

      for (int j = 0; j < kURLNum; ++j) {
        if (i != j && edges[i][j]) {
          res.push_back(urls[j]);
        }
      }
      break;
    }
    return res;
  }
};

#define Log(...)                \
  fprintf(stderr, __VA_ARGS__); \
  fprintf(stderr, "\n")

template <typename T>
class BlockingQueue {
 public:
  BlockingQueue() : head_(new Node), tail_(head_), size_(0) {}
  ~BlockingQueue() {}

  void Push(const T& value) {
    std::lock_guard<std::mutex> lk(tail_mutex_);
    tail_->value = value;
    PushNewTail();
  }

  T& Push(T&& value) {
    std::lock_guard<std::mutex> lk(tail_mutex_);
    tail_->value = std::move(value);
    PushNewTail();
    return tail_->value;
  }

  bool TryPop(T& value) {
    std::lock_guard<std::mutex> lk(head_mutex_);
    if (head_ == GetTail()) {
      return false;
    }

    value = std::move(head_->value);
    head_ = head_->next;
    return true;
  }

  // block until queue not empty
  T Pop() {
    std::unique_lock<std::mutex> lk(head_mutex_);
    cond_var_.wait(lk, [this] { return head_ != GetTail(); });

    T value = std::move(head_->value);
    head_ = head_->next;
    return value;
  }

  bool Empty() {
    std::unique_lock<std::mutex> lk(head_mutex_);
    return head_ == GetTail();
  }

 private:
  struct Node;

  void PushNewTail() {
    Node* new_tail = new Node;
    tail_->next = new_tail;
    tail_ = new_tail;
    cond_var_.notify_one();
  }

  Node* GetTail() const {
    std::lock_guard<std::mutex> lk(tail_mutex_);
    return tail_;
  }

  struct Node {
    T value;
    Node* next;

    Node() {}
    Node(const T& v) : value(v), next(nullptr) {}
    Node(T&& v) : value(std::move(v)), next(nullptr) {}
  };

  std::mutex head_mutex_;
  mutable std::mutex tail_mutex_;
  std::condition_variable cond_var_;
  Node* head_;
  Node* tail_;
  int size_;
};

class WorkQueue;
class Work {
 public:
  Work() {}
  ~Work() {}

  Work(std::function<void(void)>& func, std::promise<void>& promise)
      : func_(std::move(func)),
        promise_(std::move(promise)),
        future_(promise_.get_future()) {}

  Work(const Work& work) = delete;

  Work(Work&& work)
      : func_(std::move(work.func_)),
        promise_(std::move(work.promise_)),
        future_(std::move(work.future_)) {}

  Work& operator=(const Work& work) = delete;

  Work& operator=(Work&& work) {
    func_ = std::move(work.func_);
    promise_ = std::move(work.promise_);
    future_ = std::move(work.future_);
    return *this;
  }

  void WaitFinish() { future_.wait(); }

 private:
  friend WorkQueue;
  friend Work;

  const std::function<void(void)>& GetFunction() const { return func_; }
  void Finish() { promise_.set_value(); }

  std::function<void(void)> func_;
  std::promise<void> promise_;
  std::future<void> future_;
};

class WorkQueue {
 public:
  WorkQueue(int thread_num)
      : thread_num_(thread_num), start_(false), stop_(false) {
    InitThread();
  }
  ~WorkQueue() {}

  std::shared_ptr<Work> Schedule(std::function<void(void)>& func) {
    return Schedule(std::move(func));
  }

  std::shared_ptr<Work> Schedule(std::function<void(void)>&& func) {
    std::promise<void> promise;
    std::shared_ptr<Work> pwork(new Work(func, promise));
    queue_.Push(pwork);
    cond_.notify_one();
    return pwork;
  }

  void Start() {
    assert(start_ == false);
    start_ = true;
    cond_.notify_all();
  }
  void Stop() {
    assert(start_ == true);
    stop_ = true;
    cond_.notify_all();
  }

 private:
  void InitThread() {
    for (int i = 0; i < thread_num_; ++i) {
      std::thread t([this] {
        while (true) {
          std::unique_lock<std::mutex> lk(mutex_);
          cond_.wait(lk,
                     [this] { return (start_ && !queue_.Empty()) || stop_; });
          if (stop_) {
            return;
          }

          std::shared_ptr<Work> pwork = queue_.Pop();
          lk.unlock();

          auto func = pwork->GetFunction();
          func();
          pwork->Finish();
        }
      });
      t.detach();
    }
  }

  int thread_num_;
  bool start_;
  bool stop_;
  std::mutex mutex_;
  std::condition_variable cond_;
  BlockingQueue<std::shared_ptr<Work>> queue_;
};

class Solution {
 public:
  Solution() : work_queue_(8) {}
  ~Solution() {}
  std::vector<std::string> crawl(std::string start_url,
                                 HtmlParser html_parser) {
    std::string host_name = GetHostName(start_url);

    work_queue_.Start();
    std::shared_ptr<Work> pwork = work_queue_.Schedule(
        [&, this] { DoCrawl(host_name, start_url, html_parser); });
    pwork->WaitFinish();
    work_queue_.Stop();

    std::vector<std::string> res;
    for (const std::string& url : url_set_) {
      res.push_back(url);
    }
    return res;
  }

 private:
  std::string GetHostName(const std::string& url) {
    std::string parsed_url = url.substr(7, url.size() - 7);
    int index = parsed_url.find_first_of('/');
    return index > 0 ? parsed_url.substr(0, index) : parsed_url;
  }

  void DoCrawl(const std::string& host_name, const std::string& url,
               HtmlParser& html_parser) {
    if (ExistURL(url)) {
      return;
    }

    if (GetHostName(url) != host_name) {
      return;
    }

    // Log("Insert >>>>>>>>>>>>>>>%s", url.c_str());
    InsertURL(url);

    std::vector<std::string> urls = html_parser.getUrls(url);
    std::vector<std::shared_ptr<Work>> pworks;
    for (const std::string& sub_url : urls) {
      std::shared_ptr<Work> pwork = work_queue_.Schedule(
          [&, this] { DoCrawl(host_name, sub_url, html_parser); });
      pworks.push_back(pwork);
    }

    for (auto pwork : pworks) {
      pwork->WaitFinish();
    }
  }

  void Dump() {
    std::lock_guard<std::mutex> lk(url_set_mutex_);
    Log(">>>>>>>>>>>>>>>>");
    for (const auto& url : url_set_) {
      Log("%s", url.c_str());
    }
  }

  void InsertURL(const std::string& url) {
    std::lock_guard<std::mutex> lk(url_set_mutex_);
    url_set_.insert(url);
  }

  bool ExistURL(const std::string& url) {
    std::lock_guard<std::mutex> lk(url_set_mutex_);
    return url_set_.find(url) != url_set_.end();
  }

  WorkQueue work_queue_;
  std::unordered_set<std::string> url_set_;
  std::mutex url_set_mutex_;
};

int main(int argc, char const* argv[]) {
  memset(edges, -1, sizeof(edges));
  edges[2][0] = 1;
  edges[2][1] = 1;
  edges[3][2] = 1;
  edges[3][1] = 1;
  edges[0][4] = 1;

  Solution s;
  HtmlParser parser;
  std::vector<std::string> urls =
      s.crawl("http://news.yahoo.com/news/topics/", parser);
  for (const std::string& url : urls) {
    Log("s=%s", url.c_str());
  }

  // std::string url = "http://news.yahoo.com/news/topics/";
  // std::string res = s.GetHostName(url);

  // Log("res=%s", res.c_str());

  // BlockingQueue<Work> queue;
  // Work work;
  // queue.Push(std::move(work));

  // std::promise<void> promise;
  // std::future<void> future = promise.get_future();

  // std::thread t([&] {
  //   Log("1111111111");
  //   // promise.set_value();
  // });

  // Log("2222222222");
  // future.wait();
  // Log("333333333");

  // t.join();

  return 0;
}
