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

// dijsktra
class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    unordered_map<int, unordered_map<int, int>> G;
    for (int i = 0; i < n; ++i) {
      G[i][i] = 0;
    }

    for (auto const& edge : edges) {
      int v1 = edge[0];
      int v2 = edge[1];
      int w = edge[2];
      G[v1][v2] = G[v2][v1] = w;
    }

    int min_cities = INT_MAX;
    int min_id = -1;

    using iipair = pair<int, int>;
    for (int v = 0; v < n; ++v) {
      vector<int> dis(n, INT_MAX);
      priority_queue<iipair, vector<iipair>, greater<iipair>> pq;
      pq.emplace(0, v);
      dis[v] = 0;
      while (!pq.empty()) {
        int from = pq.top().second;
        pq.pop();

        for (auto const& pair : G[from]) {
          int to = pair.first;
          int w = pair.second;
          if (dis[from] + w < dis[to]) {
            dis[to] = dis[from] + w;
            pq.emplace(dis[from] + w, to);
          }
        }
      }

      int cities = 0;
      for (int d : dis) {
        if (d <= distanceThreshold) {
          ++cities;
        }
      }

      if (cities <= min_cities) {
        min_cities = cities;
        min_id = max(v, min_id);
      }
    }
    return min_id;
  }
};

int main(int argc, char const* argv[]) {
  /* code */

  Solution s;
  vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3},
                               {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
  log("%d\n", s.findTheCity(5, edges, 2));
  return 0;
}
