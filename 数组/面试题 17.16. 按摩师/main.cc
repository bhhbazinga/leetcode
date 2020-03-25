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
#include <cmath>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;
// class Solution {
//  public:
//   int massage(vector<int>& nums) {
//     int n = nums.size();
//     if (n <= 0) return 0;
//     vector<vector<int>> dp(n, vector<int>(2));
//     dp[0][0] = 0;
//     dp[0][1] = nums[0];
//     int dp0 = 0;
//     for (int i = 1; i < n; ++i) {
//       dp[i][1] = nums[i] + dp[i - 1][0];
//       dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
//     }
//     return max(dp[n - 1][0], dp[n - 1][1]);
//   }
// };

class Solution {
 public:
  int massage(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) return 0;
    int dp0 = 0, dp1 = nums[0];
    for (int i = 1; i < n; ++i) {
      int old_dp0 = dp0;
      int old_dp1=dp1;
      dp1 = nums[i] + old_dp0;
      dp0 = max(old_dp0, old_dp1);
    }
    return max(dp0, dp1);
  }
};
using namespace std;
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {2, 7, 9, 3, 1};
  log("%d\n", s.massage(nums));
  return 0;
}
