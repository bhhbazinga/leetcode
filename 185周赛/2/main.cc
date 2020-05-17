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
  bool kLengthApart(vector<int>& nums, int k) {
    int i = -1, j = -1;
    for (int k = 0; k < nums.size(); ++k) {
      if (nums[k] == 1) {
        i = k;
        break;
      }
    }
    if (i == -1) return true;

    j = i + 1;
    int cnt = 0;
    while (j < nums.size()) {
      if (nums[j] == 0) {
        ++cnt;
      } else {
        if (cnt < k) return false;
        i = j;
        cnt = 0;
      }
      ++j;
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
