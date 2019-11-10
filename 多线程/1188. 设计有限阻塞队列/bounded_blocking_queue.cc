#include <condition_variable>
#include <mutex>
#include <queue>

class BoundedBlockingQueue {
 public:
  BoundedBlockingQueue(int capacity) : capacity_(capacity) {}

  void enqueue(int element) {
    std::unique_lock<std::mutex> lk(mutex_);
    cond_produce_.wait(lk, [this] { return queue_.size() < capacity_; });
    queue_.push(element);
    cond_consume_.notify_one();
  }

  int dequeue() {
    std::unique_lock<std::mutex> lk(mutex_);
    cond_consume_.wait(lk, [this] { return queue_.size() > 0; });
    int res = queue_.front();
    queue_.pop();
    cond_produce_.notify_one();
    return res;
  }

  int size() {
    std::lock_guard<std::mutex> lk(mutex_);
    return queue_.size();
  }

 private:
  int capacity_;
  std::queue<int> queue_;
  std::mutex mutex_;
  std::condition_variable cond_produce_;
  std::condition_variable cond_consume_;
};