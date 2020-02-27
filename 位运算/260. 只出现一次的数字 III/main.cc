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

// class Solution {
//  public:
//   vector<int> singleNumber(vector<int>& nums) {
//     unordered_map<int, int> num2cnt;
//     for (int i = 0; i < nums.size(); ++i) {
//       ++num2cnt[nums[i]];
//     }

//     vector<int> res;
//     for (auto& pair : num2cnt) {
//       if (pair.second <= 1) {
//         res.push_back(pair.first);
//         if (res.size() >= 2) {
//           return res;
//         }
//       }
//     }
//     return res;
//   }
// };

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    int xor_ = 0;
    for (int num : nums) {
      xor_ ^= num;
    }

    int mask = xor_ & (-xor_);
    int x = 0,y = 0;
    for (int num : nums) {
      if (num & mask == 0) {
        x ^= num;
      } else {
        y ^= num;
      }
    }
    return {x, y};
  }
};

int main(long argc, char const* argv[]) { return 0; }
