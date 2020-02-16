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
  int countNegatives(vector<vector<int>>& grid) {
    int res = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[i].size(); ++j) {
        res += (grid[i][j] < 0);
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
