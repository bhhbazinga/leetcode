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

// dp:
// class Solution {
//  public:
//   bool canJump(vector<int>& nums) {
//     int n = nums.size();
//     vector<bool> dp(n, false);
//     dp[0] = true;

//     for (int i = 0; i < n; ++i) {
//       for (int j = i - 1; j >= 0; --j) {
//         if (dp[j] && j + nums[j] >= i) {
// 如果左边的点可以达到，并且这个点可以跳到当前点，则更新当前点为true
//           dp[i] = true;
//           break;
//         }
//       }
//     }

//     return dp[n - 1];
//   }
// };

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > k) return false;
      k = max(k, i + nums[i]);
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> nums = {8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1,
                      6, 3, 5, 1, 2, 6, 6, 0, 4, 8, 6, 0, 3, 2, 8, 7, 6,
                      5, 1, 7, 0, 3, 4, 8, 3, 5, 9, 0, 4, 0, 1, 0, 5, 9,
                      2, 0, 7, 0, 2, 1, 0, 8, 2, 5, 1, 2, 3, 9, 7, 4, 7,
                      0, 0, 1, 8, 5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5};
  log("%d\n", s.canJump(nums));
  return 0;
}
