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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;

class Solution {
  static const int mod = 1e9 + 7;

 public:
  int numOfWays(int n) {
    long dp[5005][3][3][3];
    memset(dp, 0, sizeof(long) * 5001 * 3 * 3 * 3);
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
          dp[1][j][k][l] = j != k && k != l;
        }
      }
    }

    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          for (int l = 0; l < 3; ++l) {
            for (int jj = 0; jj < 3; ++jj) {
              for (int kk = 0; kk < 3; ++kk) {
                for (int ll = 0; ll < 3; ++ll) {
                  if (j != k && k != l && j != jj && k != kk && l != ll) {
                    (dp[i][j][k][l] += dp[i - 1][jj][kk][ll]) %= mod;
                  }
                }
              }
            }
          }
        }
      }
    }

    long res = 0;
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
          (res += dp[n][j][k][l]) %= mod;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  log("%d\n", s.numOfWays(5000));
  return 0;
}
