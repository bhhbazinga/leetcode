#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int len = nums.size();
    int dp[len];
    dp[0] = nums[0];
    int max = dp[0];
    for (int i = 1; i < len; ++i) {
      dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
      max = std::max(dp[i], max);
    }
    return max;
  }
};