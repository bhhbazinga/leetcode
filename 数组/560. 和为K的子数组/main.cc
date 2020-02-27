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
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> sum(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + nums[i - 1];
    }

    int cnt = 0;
    for (int i = 0; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (sum[j] - sum[i] == k) {
          ++cnt;
        }
      }
    }
    return cnt;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 1, 1};
  log("%d\n", s.subarraySum(nums, 2));
  return 0;
}
