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
class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int> nums) {
    vector<int> res(nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      for (int j = 0; j < nums.size(); ++j) {
        if (i != j && nums[j] < num) {
          ++res[i];
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  s.smallerNumbersThanCurrent({8, 1, 2, 2, 3});
  s.smallerNumbersThanCurrent({6, 5, 4, 8});
  s.smallerNumbersThanCurrent({7, 7, 7, 7});
  return 0;
}
