#include <algorithm>
#include <climits>
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

class Solution {
 public:
  struct Node {
    Node(int i_, int j_, int cost_) : i(i_), j(j_), cost(cost_) {}
    int i, j;
    int cost;
  };

  int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int minCost(vector<vector<int>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    // vector<vector<bool>> vis(m, vector<bool>(n, false));
    vector<vector<int>> cost_min(m, vector<int>(n, INT_MAX));
    queue<Node> q;
    // vis[0][0] = true;
    cost_min[0][0] = 0;
    q.emplace(0, 0, 0);
    int ans = INT_MAX;
    while (!q.empty()) {
      Node cur = q.front();
      q.pop();
      if (cur.i == m - 1 && cur.j == n - 1 && cur.cost < ans) {
        ans = cur.cost;
        continue;
      }
      for (int i = 0; i < 4; ++i) {
        int next_i = cur.i + dir[i][0];
        int next_j = cur.j + dir[i][1];
        if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n) {
          int add_cost = i + 1 != grid[cur.i][cur.j];
          int next_cost = cur.cost + add_cost;
          if (next_cost < cost_min[next_i][next_j]) {
            cost_min[next_i][next_j] = next_cost;
            q.emplace(next_i, next_j, next_cost);
          }
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  log("%d\n",
      s.minCost({{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}}));
  return 0;
}
