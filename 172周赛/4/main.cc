#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
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
  int minTaps(int n, vector<int>& ranges) {
    vector<pair<int, int>> res;
    for (int i = 0; i < n + 1; ++i) {
      int l = i - ranges[i];
      l = l < 0 ? 0 : l;
      int r = i + ranges[i];
      if (l != r) res.emplace_back(l, r);
    }

    if (res.empty()) return -1;

    sort(res.begin(), res.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) {
           if (a.first != b.first) return a.first < b.first;

           return a.second < b.second;
         });

    int l = res[0].first;
    if (l > 0) return -1;

    int r = res[0].second;
    int cur = 0;
    for (int i = 1; i < res.size(); ++i) {
      if (res[i].first <= 0) {
        if (res[i].second >= r) {
          r = res[i].second;
          cur = i;
        }
      } else
        break;
    }

    int cnt = 1;
    while (r < n) {
      bool ok = false;
      int max_r = r;
      for (int i = cur + 1; i < res.size(); ++i) {
        if (res[i].first <= r) {
          ok = true;
          max_r = max<int>(max_r, res[i].second);
          cur = i;
        } else
          break;
      }

      if (!ok) return -1;

      ++cnt;
      r = max_r;
    }

    return cnt;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> ranges = {3,4,1,1,0,0};

  log("-----------------------\n%d\n", s.minTaps(ranges.size() - 1, ranges));
  return 0;
}
