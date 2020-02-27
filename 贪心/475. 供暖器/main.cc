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

class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(heaters.begin(), heaters.end());
    int res = INT_MIN;
    for (int i = 0; i < houses.size(); ++i) {
      int cur_min = INT_MAX;
      auto it = lower_bound(heaters.begin(), heaters.end(), houses[i]);
      if (it == heaters.end()) {
        res = max(res, abs(heaters[heaters.size() - 1] - houses[i]));
        continue;
      }
      cur_min = min(cur_min, abs(*it - houses[i]));
      --it;
      if (it >= heaters.begin()) {
        cur_min = min(cur_min, abs(*it - houses[i]));
      }
      res = max(res, cur_min);
    }
    return res;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  vector<int> houses = {1, 2, 3, 5, 15};
  vector<int> heaters = {2, 30};
  log("%d\n", s.findRadius(houses, heaters));
  return 0;
}
