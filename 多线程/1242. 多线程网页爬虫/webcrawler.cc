/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

#include <unistd.h>
#include <atomic>
#include <cassert>
#include <chrono>
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

#define Log(...)                                              \
  fprintf(stderr, "[thread-%d]", std::this_thread::get_id()); \
  fprintf(stderr, __VA_ARGS__);                               \
  fprintf(stderr, "\n")

class HtmlParser {
 public:
  std::vector<std::string> getUrls(const std::string& url) {
    sleep(rand() % 3);
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

template <typename T>
class BlockingQueue {
 public:
  BlockingQueue() : head_(new Node), tail_(head_) {}
  ~BlockingQueue() { delete tail_; }

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

    Node* old_head = head_;
    value = std::move(old_head->value);
    head_ = old_head->next;
    delete old_head;
    return true;
  }

  T Pop() {
    std::unique_lock<std::mutex> lk(head_mutex_);
    cond_var_.wait(lk, [this] { return head_ != GetTail(); });

    Node* old_head = head_;
    T value = std::move(old_head->value);
    head_ = old_head->next;
    delete old_head;
    return value;
  }

  std::shared_ptr<T> PopFor(int millisec) {
    std::unique_lock<std::mutex> lk(head_mutex_);
    cond_var_.wait_for(lk, std::chrono::milliseconds(millisec),
                       [this] { return head_ != GetTail(); });

    if (head_ == GetTail()) {
      return nullptr;
    }

    Node* old_head = head_;
    std::shared_ptr<T> value = std::make_shared<T>(std::move(old_head->value));
    head_ = old_head->next;
    delete old_head;
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
};

class Solution {
 public:
  std::vector<std::string> crawl(std::string start_url,
                                 HtmlParser html_parser) {
    BlockingQueue<std::string> request_queue;
    std::string host_name = GetHostName(start_url);
    request_queue.Push(start_url);

    int len = std::thread::hardware_concurrency();
    std::thread* threads[len];
    bool running[len];
    memset(running, 0, sizeof(running));

    for (int i = 0; i < len; ++i) {
      std::thread* t = new std::thread([&, i, this] {
        while (true) {
          std::shared_ptr<std::string> purl = request_queue.PopFor(1);
          if (purl == nullptr) {
            bool finish = true;
            for (int j = 0; j < len; ++j) {
              if (running[j]) {
                finish = false;
                break;
              }
            }
            if (finish) {
              return;
            } else {
              continue;
            }
          }

          running[i] = true;
          if (GetHostName(*purl) == host_name && TryInsertURL(*purl)) {
            std::vector<std::string> urls = html_parser.getUrls(*purl);
            for (std::string& sub_url : urls) {
              request_queue.Push(sub_url);
            }
          }
          running[i] = false;
        }
      });
      threads[i] = t;
    }

    for (int i = 0; i < len; ++i) {
      threads[i]->join();
      delete threads[i];
    }

    std::vector<std::string> res;
    for (const std::string& url : url_set_) {
      res.push_back(url);
    }
    return res;
  }

  std::string GetHostName(const std::string& url) {
    std::string parsed_url = url.substr(7, url.size() - 7);
    int index = parsed_url.find_first_of('/');
    return index > 0 ? parsed_url.substr(0, index) : parsed_url;
  }

  bool TryInsertURL(const std::string& url) {
    std::lock_guard<std::mutex> lk(url_set_mutex_);
    if (url_set_.find(url) != url_set_.end()) {
      return false;
    }
    url_set_.insert(url);
    return true;
  }

 private:
  std::unordered_set<std::string> url_set_;
  std::mutex url_set_mutex_;
};

int main(int argc, char const* argv[]) {
  memset(edges, -1, sizeof(edges));
  edges[1][2] = 1;
  edges[2][0] = 1;
  edges[0][2] = 1;
  edges[2][1] = 1;
  edges[3][2] = 1;
  edges[3][1] = 1;
  edges[0][4] = 1;
  edges[4][0] = 1;

  Solution s;
  HtmlParser parser;
  std::vector<std::string> urls =
      s.crawl("http://news.yahoo.com/news/topics/", parser);
  for (const std::string& url : urls) {
    Log("s=%s", url.c_str());
  }
  return 0;
}
