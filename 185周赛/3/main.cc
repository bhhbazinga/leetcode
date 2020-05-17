#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <numeric>
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
  int longestSubarray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<vector<int>> mins(n, vector<int>(n));
    vector<vector<int>> maxs(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      int min_num = nums[i];
      int max_num = nums[i];
      for (int j = i; j < n; ++j) {
        min_num = min(min_num, nums[j]);
        max_num = max(max_num, nums[j]);
        mins[i][j] = min_num;
        maxs[i][j] = max_num;
      }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + res; j < n; ++j) {
        if (abs(mins[i][j] - maxs[i][j]) <= limit) {
          res = max(res, j - i + 1);
        }
      }
    }
    return res;
  }
};

// class NumArray {
//  private:
//   vector<int> tree_;
//   void Build(vector<int>& nums) {
//     int n = nums.size();
//     tree_.resize(2 * n);
//     for (int i = n; i < 2 * n; ++i) {
//       tree_[i] = nums[i - n];
//     }
//     for (int i = n - 1; i > 0; --i) {
//       tree_[i] = tree_[i * 2] + tree_[i * 2 + 1];
//     }
//   }

//   int Query(int i, int j) {
//     int n = tree_.size() / 2;
//     int l = n + i, r = n + j;
//     int sum = 0;
//     while (l <= r) {
//       if (l % 2 != 0) {
//         sum += tree_[l];
//         ++l;
//       }
//       if (r % 2 != 1) {
//         sum += tree_[r];
//         --r;
//       }
//       l /= 2;
//       r /= 2;
//     }
//     return sum;
//   }

//  public:
//   NumArray(vector<int>& nums) { Build(nums); }
// };

int main(int argc, char const* argv[]) { return 0; }
