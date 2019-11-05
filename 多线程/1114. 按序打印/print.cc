#include <atomic>
#include <condition_variable>
#include <cstdio>
#include <functional>
#include <mutex>
#include <thread>

class Foo {
 public:
  Foo() : ready1_(false), ready2_(false) {}

  void first(std::function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();

    ready1_ = true;
    cond_var1_.notify_one();
  }

  void second(std::function<void()> printSecond) {
    std::unique_lock<std::mutex> lk(mutex);
    cond_var1_.wait(lk, [this]() { return ready1_; });
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    ready2_ = true;
    lk.unlock();

    cond_var2_.notify_one();
  }

  void third(std::function<void()> printThird) {
    std::unique_lock<std::mutex> lk(mutex);
    cond_var2_.wait(lk, [this]() { return ready2_; });

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }

 private:
  std::mutex mutex;
  std::condition_variable cond_var1_;
  std::condition_variable cond_var2_;
  bool ready1_;
  bool ready2_;
};