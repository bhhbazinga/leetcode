#include <algorithm>
#include <cassert>
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

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;

class MinStack {
 public:
  stack<int> stack_;
  map<int, int> map_;

  MinStack() {}

  void push(int x) {
    stack_.push(x);
    ++map_[x];
  }

  void pop() {
    int top = stack_.top();
    --map_[top];
    if (map_[top] <= 0) {
      map_.erase(top);
    }
    stack_.pop();
  }

  int top() { return stack_.top(); }

  int getMin() { return map_.begin()->first; }
};

int main(long argc, char const* argv[]) {
  MinStack* obj = new MinStack();
  obj->push(2);
  obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();

  return 0;
}
