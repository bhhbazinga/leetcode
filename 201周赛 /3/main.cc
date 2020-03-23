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
  struct Node {
    Node(int i_, int j_) : i(i_), j(j_) {}
    int i, j;
  };

  void TryLeft(int cur_i, int cur_j, vector<vector<int>>& grid) {
    int next_i = cur_i;
    int next_j = cur_j - 1;
    if (next_j >= 0 && !vis[next_i][next_j]) {
      int next_g = grid[next_i][next_j];
      if (next_g == 1 || next_g == 4 || next_g == 6) {
        vis[next_i][next_j] = true;
        q.emplace(next_i, next_j);
      }
    }
  }

  void TryRight(int cur_i, int cur_j, vector<vector<int>>& grid) {
    int next_i = cur_i;
    int next_j = cur_j + 1;
    if (next_j < n && !vis[next_i][next_j]) {
      int next_g = grid[next_i][next_j];
      if (next_g == 1 || next_g == 3 || next_g == 5) {
        vis[next_i][next_j] = true;
        q.emplace(next_i, next_j);
      }
    }
  }

  void TryUp(int cur_i, int cur_j, vector<vector<int>>& grid) {
    int next_i = cur_i - 1;
    int next_j = cur_j;
    if (next_i >= 0 && !vis[next_i][next_j]) {
      int next_g = grid[next_i][next_j];
      if (next_g == 2 || next_g == 3 || next_g == 4) {
        vis[next_i][next_j] = true;
        q.emplace(next_i, next_j);
      }
    }
  }

  void TryDown(int cur_i, int cur_j, vector<vector<int>>& grid) {
    int next_i = cur_i + 1;
    int next_j = cur_j;
    if (next_i < m && !vis[next_i][next_j]) {
      int next_g = grid[next_i][next_j];
      if (next_g == 2 || next_g == 5 || next_g == 6) {
        vis[next_i][next_j] = true;
        q.emplace(next_i, next_j);
      }
    }
  }

  int m, n;
  vector<vector<int>> vis;
  queue<Node> q;

 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    vis = vector<vector<int>>(m, vector<int>(n));
    q = queue<Node>();
    vis[0][0] = true;
    q.emplace(0, 0);
    while (!q.empty()) {
      Node cur = q.front();
      q.pop();
      if (cur.i == m - 1 && cur.j == n - 1) return true;
      int next_i, next_j;
      int next_g;
      switch (grid[cur.i][cur.j]) {
        case 1:
          TryLeft(cur.i, cur.j, grid);
          TryRight(cur.i, cur.j, grid);
          break;
        case 2:
          TryUp(cur.i, cur.j, grid);
          TryDown(cur.i, cur.j, grid);
          break;
        case 3:
          TryLeft(cur.i, cur.j, grid);
          TryDown(cur.i, cur.j, grid);
          break;
        case 4:
          TryRight(cur.i, cur.j, grid);
          TryDown(cur.i, cur.j, grid);
          break;
        case 5:
          TryUp(cur.i, cur.j, grid);
          TryLeft(cur.i, cur.j, grid);
          break;
        case 6:
          TryUp(cur.i, cur.j, grid);
          TryRight(cur.i, cur.j, grid);
          break;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {}