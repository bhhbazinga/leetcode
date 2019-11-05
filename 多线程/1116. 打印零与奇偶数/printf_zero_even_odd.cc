#include <condition_variable>
#include <functional>
#include <mutex>
#include <thread>

class ZeroEvenOdd {
 public:
  ZeroEvenOdd(int n) : n_(n), step_(-1) {}

  // printNumber(x) outputs "x", where x is an integer.
  void zero(std::function<void(int)> printNumber) {
    for (int i = 1; i <= n_; ++i) {
      std::unique_lock<std::mutex> lk(mu_);
      cv_zero_.wait(lk, [this] { return step_ == -1; });
      printNumber(0);
      lk.unlock();

      step_ = i % 2;
      if (step_ == 0) {
        cv_even_.notify_one();
      } else {
        cv_odd_.notify_one();
      }
    }
  }

  void even(std::function<void(int)> printNumber) {
    for (int i = 2; i <= n_; i += 2) {
      std::unique_lock<std::mutex> lk(mu_);
      cv_even_.wait(lk, [this] { return step_ == 0; });
      printNumber(i);
      step_ = -1;
      lk.unlock();

      cv_zero_.notify_one();
    }
  }

  void odd(std::function<void(int)> printNumber) {
    for (int i = 1; i <= n_; i += 2) {
      std::unique_lock<std::mutex> lk(mu_);
      cv_odd_.wait(lk, [this] { return step_ == 1; });
      printNumber(i);
      step_ = -1;
      lk.unlock();

      cv_zero_.notify_one();
    }
  }

 private:
  int n_;
  int step_;
  std::mutex mu_;
  std::condition_variable cv_zero_;
  std::condition_variable cv_even_;
  std::condition_variable cv_odd_;
};

int main(int argc, char const *argv[]) {
  ZeroEvenOdd zeo(5);

  auto func = [](int x) { fprintf(stderr, "%d", x); };

  std::thread t1(&ZeroEvenOdd::zero, &zeo, func);
  std::thread t2(&ZeroEvenOdd::even, &zeo, func);
  std::thread t3(&ZeroEvenOdd::odd, &zeo, func);

  t1.join();
  t2.join();
  t3.join();
  return 0;
}
