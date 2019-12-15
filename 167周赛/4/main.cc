#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <vector>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

const int path[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int kMaxM = 40;

class Solution {
 public:
  struct Node {
    Node(int i_, int j_, int k_, int step_)
        : i(i_), j(j_), k(k_), step(step_) {}

    Node() {}

    int i, j;
    int k;
    int step;

    bool operator<(const Node& other) const {
      if (step != other.step) {
        return step < other.step;
      }
      return k > other.k;
    }

    bool operator>(const Node& other) const {
      return !(*this == other) && !(*this < other);
    }

    bool operator>=(const Node& other) const {
      return *this > other || *this == other;
    }

    bool operator==(const Node& other) const {
      return !(*this < other) && !(other < *this);
    }
  };

  int shortestPath(std::vector<std::vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();

    // int visit[kMaxM][kMaxM];
    // memset(&visit[0][0], -1, sizeof(visit[0][0]) * kMaxM * kMaxM);
    // return bfs(grid, k, visit, m, n);

    Node visit[kMaxM][kMaxM];
    for (int i = 0; i < kMaxM; ++i) {
      for (int j = 0; j < kMaxM; ++j) {
        visit[i][j].k = -1;
        visit[i][j].step = INT_MAX;
      }
    }

    Node firs_node = Node(0, 0, k, 0);
    dfs(grid, firs_node, visit, m, n);
    return visit[m - 1][n - 1].step == INT_MAX ? -1 : visit[m - 1][n - 1].step;
  }

  // int bfs(std::vector<std::vector<int>>& grid, int k, int
  // visit[kMaxM][kMaxM],
  //         int m, int n) {
  //   visit[0][0] = -1;
  //   std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
  //   q.emplace(0, 0, k, 0);

  //   while (!q.empty()) {
  //     const Node& node = q.top();
  //     int i = node.i;
  //     int j = node.j;
  //     int step = node.step;
  //     int k = node.k;
  //     q.pop();

  //     if (i == m - 1 && j == n - 1) {
  //       return step;
  //     }

  //     for (int index = 0; index < 4; ++index) {
  //       int next_i = i + path[index][0];
  //       int next_j = j + path[index][1];
  //       if (next_i >= m || next_i < 0 || next_j >= n || next_j < 0) {
  //         continue;
  //       }

  //       int next_k = k;
  //       if (grid[next_i][next_j] == 1) {
  //         if (next_k <= 0) {
  //           continue;
  //         }
  //         --next_k;
  //       }

  //       if (next_k > visit[next_i][next_j]) {
  //         visit[next_i][next_j] = next_k;
  //         q.emplace(next_i, next_j, next_k, step + 1);
  //       }
  //     }
  //   }

  //   return -1;
  // }

  void dfs(std::vector<std::vector<int>>& grid, Node& cur_node,
           Node visit[kMaxM][kMaxM], int m, int n) {
    int i = cur_node.i, j = cur_node.j;
    if (cur_node >= visit[i][j]) {
      return;
    }

    visit[i][j] = cur_node;
    if (i == m - 1 && j == n - 1) {
      return;
    }

    for (int index = 0; index < 4; ++index) {
      int next_i = i + path[index][0];
      int next_j = j + path[index][1];
      if (next_i < m && next_i >= 0 && next_j < n && next_j >= 0) {
        bool block = grid[next_i][next_j] == 1;
        if (block) {
          if (cur_node.k > 0) {
            --cur_node.k;
          } else {
            continue;
          }
        }

        ++cur_node.step;
        cur_node.i = next_i;
        cur_node.j = next_j;
        dfs(grid, cur_node, visit, m, n);
        if (block) {
          ++cur_node.k;
        }
        cur_node.i = i;
        cur_node.j = j;
        --cur_node.step;
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  std::vector<std::vector<int>> v = {
      // {0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1},
      // {0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1},
      // {1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
      // {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1},
      // {1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1},
      // {0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1},
      // {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1},
      // {1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0},
      // {0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0},
      // {0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
      // {0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0}};

  {{0, 1, 0, 0, 0, 1, 0, 0},
   {0, 1, 0, 1, 0, 1, 0, 1},
   {0, 0, 0, 1, 0, 0, 1, 0}}};

  printf("%d\n", s.shortestPath(v, 1));
  return 0;
}
