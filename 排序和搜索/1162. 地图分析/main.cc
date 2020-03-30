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
#include <tuple>
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
    Node() : i(-1), j(-1), s(-1) {}
    Node(int i_, int j_, int s_) : i(i_), j(j_), s(s_) {}
    int i, j, s;
  };

  const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

 public:
  int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<Node> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          q.emplace(i, j, -1);
        }
      }
    }

    Node cur;
    while (!q.empty()) {
      cur = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int ni = cur.i + dir[i][0];
        int nj = cur.j + dir[i][1];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 0) {
          grid[ni][nj] = 1;
          q.emplace(ni, nj, cur.s + 1);
        }
      }
    }
    return cur.s == -1 ? -1 : cur.s + 1;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  // vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  log("%d\n", s.maxDistance(grid));
  return 0;
}
