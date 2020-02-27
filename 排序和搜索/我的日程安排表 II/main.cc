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
class MyCalendarTwo {
 private:
  vector<pair<int, int>> overlaps;
  vector<pair<int, int>> normals;

 public:
  MyCalendarTwo() {}

  bool Collision(int start, int end, int other_start, int other_end) {
    return max(start, other_start) < min(end, other_end);
  }

  bool book(int start, int end) {
    for (auto const& pair : overlaps) {
      if (Collision(pair.first, pair.second, start, end)) return false;
    }

    for (auto const& pair : normals) {
      if (Collision(pair.first, pair.second, start, end)) {
        overlaps.emplace_back(max(start, pair.first), min(end, pair.second));
      }
    }

    normals.emplace_back(start, end);
    return true;
  }
};

int main(long argc, char const* argv[]) {
  MyCalendarTwo s;
  log("%d\n", s.book(10, 20));  // returns true
  log("%d\n", s.book(50, 60));  // returns true
  log("%d\n", s.book(10, 40));  // returns true
  log("%d\n", s.book(5, 15));   // returns false
  log("%d\n", s.book(5, 10));
  log("%d\n", s.book(25, 55));
  return 0;
}
