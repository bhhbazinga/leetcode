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

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;

class Solution {
 public:
  int maxEvents(vector<vector<int>>& events) {
    std::sort(events.begin(), events.end(),
              [](const vector<int>& a, const vector<int>& b) {
                //第一种排序方法：如果a,b有包含关系，被包含的排在前面
                // if (a[0] >= b[0] && a[1] <= b[1])
                //   return true;
                // else if (a[0] <= b[0] && a[1] >= b[1])
                //   return false;

                // if (a[0] != b[0]) return a[0] < b[0];
                // return a[1] < b[1];

                //第二种排序方法：按照结束时间从小到大优先排序
                return (a[1] != b[1]) ? a[1] < b[1] : a[0] < b[0];
              });

    int res = 0;
    unordered_map<int, bool> visit;
    for (int i = 0; i < events.size(); ++i) {
      // log("%d,%d->", events[i][0], events[i][1]);
      for (int day = events[i][0]; day <= events[i][1]; ++day) {
        if (!visit[day]) {
          ++res;
          visit[day] = true;
          break;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  // vector<vector<int>> events = {{1, 2}, {2, 2}, {3, 3}, {3, 4}, {3, 4}};
  // vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
  // vector<vector<int>> events = {{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
  // vector<vector<int>> events = {{1, 2}, {3, 3},{1, 5}};
  vector<vector<int>> events = {{1, 10}, {2, 2}, {2, 2}, {2, 2}, {2, 2}};
  log("\n%d\n", s.maxEvents(events));
}
