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

// 常规dp: dp[i] 表示以num[i]结尾的序列的长度
// class Solution {
//  public:
//   int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();
//     if (n <= 0) {
//       return 0;
//     }
//     vector<int> dp(n, 1);

//     int res = 1;
//     for (int i = 0; i < n; ++i) {
//       for (int j = 0; j < i; ++j) {
//         if (nums[i] > nums[j]) {
//           dp[i] = max(dp[i], dp[j] + 1);
//         }
//       }
//       res = max(res, dp[i]);
//     }
//     return res;
//   }
// };

// 二分: dp[i]表示长度为i+1的所有序列中末尾最小的数
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0 ) {
      return 0;
    }

    vector<int> dp(1, nums[0]);
    for (int num : nums) {
      auto it = lower_bound(dp.begin(), dp.end(), num);
      if (it == dp.begin()) {
        dp[0] = num;
      } else if (it == dp.end()) {
        dp.push_back(num);
      } else {
        dp[it - dp.begin()] = num;
      }
    }
    return dp.size();
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> nums = {10, 9, 2, 5, 3, 4};
  log("%d\n", s.lengthOfLIS(nums));
  return 0;
}
