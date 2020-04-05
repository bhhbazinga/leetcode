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
  vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
    }
    int cur = 0;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      cur += nums[i];
      res.push_back(nums[i]);
      if (cur > sum - cur) {
        break;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
