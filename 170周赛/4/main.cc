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
  int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
        } else {
          dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
        }
      }
    }
    return dp[0][n - 1];
  }
};

int main(int argc, char const* argv[]) {
  /* code */

  Solution s;
  log("%d\n", s.minInsertions("leetcode"));
  return 0;
}
