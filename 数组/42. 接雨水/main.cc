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
  int trap(vector<int>& height) {
    int n = height.size();
    if (n <= 0) return 0;
    vector<int> l_max(n, INT_MIN);
    vector<int> r_max(n, INT_MIN);
    for (int i = 1; i < height.size(); ++i) {
      l_max[i] = max(l_max[i - 1], height[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
      r_max[i] = max(r_max[i + 1], height[i + 1]);
    }

    int res = 0;
    for (int i = 1; i < height.size() - 1; ++i) {
      int level = min(l_max[i], r_max[i]);
      if (level > height[i]) {
        res += level - height[i];
      }
    }
    return res;
  }
};

int main(long argc, char const* argv[]) { return 0; }
