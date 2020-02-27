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
  int trapRainWater(vector<vector<int>>& heightMap) {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    struct Node {
      Node(int i_, int j_, int h_) : i(i_), j(j_), h(h_) {}
      int i, j, h;
      bool operator<(const Node& other) const { return h > other.h; }
    };

    int m = heightMap.size();
    if (m == 0) return 0;
    int n = heightMap[0].size();
    if (n == 0) return 0;
    priority_queue<Node> pq;
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
      visit[i][0] = true;
      visit[i][n - 1] = true;
      pq.emplace(i, 0, heightMap[i][0]);
      pq.emplace(i, n - 1, heightMap[i][n - 1]);
    }
    for (int i = 0; i < n; ++i) {
      visit[0][i] = true;
      visit[m - 1][i] = true;
      pq.emplace(0, i, heightMap[0][i]);
      pq.emplace(m - 1, i, heightMap[m - 1][i]);
    }

    int res = 0;
    while (!pq.empty()) {
      const Node& top = pq.top();
      int top_i = top.i;
      int top_j = top.j;
      int top_h = top.h;
      pq.pop();
      for (int i = 0; i < 4; ++i) {
        int neighbor_i = top_i + dir[i][0];
        int neighbor_j = top_j + dir[i][1];
        if (neighbor_i < m && neighbor_i >= 0 && neighbor_j < n &&
            neighbor_j >= 0 && !visit[neighbor_i][neighbor_j]) {
          visit[neighbor_i][neighbor_j] = true;
          pq.emplace(neighbor_i, neighbor_j,
                     max(heightMap[neighbor_i][neighbor_j], top_h));
          if (top_h > heightMap[neighbor_i][neighbor_j]) {
            res += top_h - heightMap[neighbor_i][neighbor_j];
          }
        }
      }
    }
    return res;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  // vector<vector<int>> heightMap = {
  //     {1, 4, 3, 1, 3, 2},
  //     {3, 2, 1, 3, 2, 4},
  //     {2, 3, 3, 2, 3, 1},
  // };

  // vector<vector<int>> heightMap = {
  //     {2, 2, 2, 2},
  //     {2, 1, 1, 2},
  //     {2, 2, 2, 2},
  // };

  vector<vector<int>> heightMap = {{12, 13, 1, 12},
                                   {13, 4, 13, 12},
                                   {13, 8, 10, 12},
                                   {12, 13, 12, 12},
                                   {13, 13, 13, 13}};
  log("%d\n", s.trapRainWater(heightMap));
  return 0;
}
