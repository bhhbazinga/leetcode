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
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  log("%d\n", s.uniquePaths(7, 3));
  return 0;
}
