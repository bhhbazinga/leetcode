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
  int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int res;
    for (int i = 0; i < n; ++i) {
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == target) return target;
        if (sum > target) {
          --k;
        } else {
          ++j;
        }
        if (abs(sum - target) < diff) {
          diff = abs(sum - target);
          res = sum;
        }
      }
    }
    return res;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {-1, 2, 1, -4};
  log("%d\n", s.threeSumClosest(nums, 1));
  return 0;
}
