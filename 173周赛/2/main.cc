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
  vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                int veganFriendly, int maxPrice,
                                int maxDistance) {
    vector<int> res;
    for (int i = 0; i < restaurants.size(); ++i) {
      auto const& r = restaurants[i];
      if (veganFriendly == 1 && r[2] != 1) continue;
      if (r[3] > maxPrice) continue;
      if (r[4] > maxDistance) continue;
      res.push_back(i);
    }

    sort(res.begin(), res.end(), [&](int a, int b) {
      if (restaurants[a][1] != restaurants[b][1])
        return restaurants[a][1] > restaurants[b][1];

      return restaurants[a][0] > restaurants[b][0];
    });

    for (int& r : res) {
      r = restaurants[r][0];
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;

  vector<vector<int>> restaurants = {{1, 4, 1, 40, 10},
                                     {2, 8, 0, 50, 5},
                                     {3, 8, 1, 30, 4},
                                     {4, 10, 0, 10, 3},
                                     {5, 1, 1, 15, 1}};

  auto v = s.filterRestaurants(restaurants, 0, 50, 10);
  for (auto x : v) {
    log("%d,", x);
  }
  return 0;
}
