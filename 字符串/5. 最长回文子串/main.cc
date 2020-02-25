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
  string longestPalindrome(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int res = 1, res_i = 0;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
        if (dp[i][j] && j - i + 1 > res) {
          res = j - i + 1;
          res_i = i;
        }
      }
    }
    return s.substr(res_i, res);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  log("%s\n", s.longestPalindrome("ababc").c_str());
  return 0;
}
