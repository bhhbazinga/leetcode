#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <list>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;

class CustomStack {
  list<int> l;
  int max_size_;

 public:
  CustomStack(int maxSize) : max_size_(maxSize) {}

  void push(int x) {
    if (l.size() == max_size_) return;
    l.insert(l.begin(), x);
  }

  int pop() {
    if (l.empty()) return -1;
    int front = l.front();
    l.erase(l.begin());
    return front;
  }

  void increment(int k, int val) {
    auto it = l.end();
    --it;
    auto begin_it = l.begin();
    --begin_it;

    for (int i = 0; it != begin_it && i < k; --it, ++i) {
      *it += val;
    }
  }
};

int main(int argc, char const* argv[]) {
  CustomStack* obj = new CustomStack(3);
  obj->push(2);
  int param_2 = obj->pop();
  obj->increment(1, val);
  return 0;
}
