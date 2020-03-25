#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
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
//   static const int kMax = 51;

//  public:
//   int surfaceArea(vector<vector<int>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();
//     int h = 0;

//     vector<vector<vector<bool>>> cube(
//         kMax, vector<vector<bool>>(kMax, vector<bool>(kMax, false)));
//     for (int i = 0; i < m; ++i) {
//       for (int j = 0; j < n; ++j) {
//         h = max(h, grid[i][j]);
//         for (int v = 0; v < grid[i][j]; ++v) {
//           cube[i][j][v] = true;
//         }
//       }
//     }

//     int res = 0;
//     for (int x = 0; x < m; ++x) {
//       for (int y = 0; y < n; ++y) {
//         for (int z = 0; z < h; ++z) {
//           if (cube[x][y][z]) {
//             int cur = 6;
//             cur -= x - 1 >= 0 && cube[x - 1][y][z];
//             cur -= y - 1 >= 0 && cube[x][y - 1][z];
//             cur -= z - 1 >= 0 && cube[x][y][z - 1];
//             cur -= x + 1 < m && cube[x + 1][y][z];
//             cur -= y + 1 < n && cube[x][y + 1][z];
//             cur -= z + 1 < h && cube[x][y][z + 1];
//             res += cur;
//           }
//         }
//       }
//     }
//     return res;
//   }
// };

class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int v = grid[i][j];
        if (v > 0) {
          res += v * 4 + 2;
          if (i - 1 >= 0) res -= min(v, grid[i - 1][j]) * 2;
          if (j - 1 >= 0) res -= min(v, grid[i][j - 1]) * 2;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  // vector<vector<int>> grid = {{2}};
  vector<vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  // vector<vector<int>> grid = {{1, 2}, {3, 4}};
  // vector<vector<int>> grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  log("%d\n", s.surfaceArea(grid));
  return 0;
}
