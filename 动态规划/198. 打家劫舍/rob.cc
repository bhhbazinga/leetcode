#include <algorithm>
#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    // 容易想到的解法
    //   int n = nums.size();
    //   if (n == 0) {
    //     return 0;
    //   } else if (n == 1) {
    //     return nums[0];
    //   } else if (n == 2) {
    //     return std::max(nums[0], nums[1]);
    //   }

    //   int dp[n];
    //   dp[0] = nums[0];
    //   dp[1] = std::max(nums[0], dp[1]);
    //   for (int i = 2; i < nums.size(); ++i) {
    //     dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    //   }
    //   return dp[n - 1];
    // }

    // dp下标从1开始，容易的解法s
    // 简化代码的写法
    int n = nums.size();
    if (n <= 0) {
      return 0;
    }
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= n; ++i) {
      dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[n];
  }
};