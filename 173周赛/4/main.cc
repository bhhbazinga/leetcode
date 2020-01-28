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
  int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (d > n) return -1;

    vector<vector<int>> maxi(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      maxi[i][i] = jobDifficulty[i];
      for (int j = i + 1; j < n; ++j) {
        maxi[i][j] = max(maxi[i][j - 1], jobDifficulty[j]);
      }
    }

    vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX / 3));
    dp[0][0] = 0;

    for (int i = 1; i <= d; ++i) {
      for (int j = i; j <= n; ++j) {
        for (int k = i - 1; k < j; ++k) {
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + maxi[k][j - 1]);
        }
      }
    }
    return dp[d][n];
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> jobDifficulty = {6, 5, 4, 3, 2, 1};
  log("%d\n", s.minDifficulty(jobDifficulty, 2));
  return 0;
}
