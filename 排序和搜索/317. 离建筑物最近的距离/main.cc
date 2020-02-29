#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
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

// 从空地出发bfs，耗时太大
// class Solution {
//  public:
//   struct Node {
//     Node(int i_, int j_, int step_) : i(i_), j(j_), step(step_) {}
//     int i, j;
//     int step;
//   };

//   int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

//   int shortestDistance(vector<vector<int>>& grid) {
//     int m = grid.size();
//     int n = grid[0].size();
//     int res_min = INT_MAX;
//     int count_1 = 0;
//     for (int i = 0; i < m; ++i) {
//       for (int j = 0; j < n; ++j) {
//         count_1 += grid[i][j] == 1;
//       }
//     }
//     for (int i = 0; i < m; ++i) {
//       for (int j = 0; j < n; ++j) {
//         res_min = min(res_min, bfs(i, j, grid, m, n, count_1, res_min));
//       }
//     }
//     return res_min == INT_MAX ? -1 : res_min;
//   }

//   int bfs(int start_i, int start_j, vector<vector<int>>& grid, int m, int n,
//           int count_1, int res_min) {
//     if (grid[start_i][start_j] != 0) return INT_MAX;

//     queue<Node> q;
//     vector<vector<bool>> vis(m, vector<bool>(n, false));
//     vis[start_i][start_j] = true;
//     q.emplace(start_i, start_j, 0);
//     int ans = 0;
//     int count = 0;
//     while (!q.empty()) {
//       Node cur = q.front();
//       q.pop();

//       if (grid[cur.i][cur.j] == 1) {
//         ++count;
//         ans += cur.step;
//         if (ans > res_min) {
//           return INT_MAX;
//         }
//         continue;
//       }

//       for (int i = 0; i < 4; ++i) {
//         int next_i = cur.i + dir[i][0];
//         int next_j = cur.j + dir[i][1];
//         if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n) {
//           if (!vis[next_i][next_j] && grid[next_i][next_j] != 2) {
//             vis[next_i][next_j] = true;
//             q.emplace(next_i, next_j, cur.step + 1);
//           }
//         }
//       }
//     }
//     return count >= count_1 ? ans : INT_MAX;
//   }
// };

class Solution {
 public:
  struct Node {
    Node(int i_, int j_, int step_) : i(i_), j(j_), step(step_) {}
    int i, j;
    int step;
  };

  int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int m, n;
  vector<vector<int>> sum;
  vector<vector<int>> count;

  int shortestDistance(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    sum = vector<vector<int>>(m, vector<int>(n, 0));
    count = vector<vector<int>>(m, vector<int>(n, 0));

    int buildings = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (1 == grid[i][j]) {
          ++buildings;
          bfs(i, j, grid);
        }
      }
    }

    int ans = INT_MAX;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (count[i][j] >= buildings) {
          ans = min(ans, sum[i][j]);
        }
      }
    }
    return ans == INT_MAX ? -1 : ans;
  }

  void bfs(int start_i, int start_j, vector<vector<int>>& grid) {
    queue<Node> q;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    vis[start_i][start_j] = true;
    q.emplace(start_i, start_j, 0);
    while (!q.empty()) {
      Node cur = q.front();
      q.pop();

      for (int i = 0; i < 4; ++i) {
        int next_i = dir[i][0] + cur.i;
        int next_j = dir[i][1] + cur.j;
        if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n) {
          if (!vis[next_i][next_j] && 0 == grid[next_i][next_j]) {
            int next_step = cur.step + 1;
            vis[next_i][next_j] = true;
            sum[next_i][next_j] += next_step;
            ++count[next_i][next_j];
            q.emplace(next_i, next_j, next_step);
          }
        }
      }
    }
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  // vector<vector<int>> v = {{1, 0, 2, 0, 1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};
  // vector<vector<int>> v = {{0, 2, 1}, {1, 0, 2}, {0, 1, 0}};
  vector<vector<int>> v = {{0, 2, 1}, {1, 0, 2}, {0, 1, 0}};
  log("%d\n", s.shortestDistance(v));
  return 0;
}
