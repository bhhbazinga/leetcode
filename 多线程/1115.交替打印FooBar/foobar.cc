#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>

class FooBar {
 public:
  FooBar(int n) : step_(0) { this->n = n; }

  void foo(std::function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lk(mu_);
      cv_.wait(lk, [this] { return step_ == 0; });
      printFoo();
      step_ = 1;
      lk.unlock();
      cv_.notify_all();
    }
  }

  void bar(std::function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      std::unique_lock<std::mutex> lk(mu_);
      cv_.wait(lk, [this] { return step_ == 1; });
      printBar();
      step_ = 0;
      lk.unlock();
      cv_.notify_all();
    }
  }

 private:
  int n;
  int step_;
  std::mutex mu_;
  std::condition_variable cv_;
};

int main(int argc, char const *argv[]) {
  FooBar fb(1);
  std::thread t1(&FooBar::foo, &fb, [] { fprintf(stderr, "foo"); });
  std::thread t2(&FooBar::bar, &fb, [] { fprintf(stderr, "bar"); });
  t1.join();
  t2.join();
  return 0;
}
