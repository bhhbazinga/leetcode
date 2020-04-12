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
// o(kn^2)
// class Solution {
//   int dp(int k, int n) {
//     if (k == 1) return n;
//     if (n == 0) return 0;

//     if (memo[k][n] != -1) return memo[k][n];
//     int res = INT_MAX;
//     for (int i = 1; i <= n; ++i) {
//       res = min(res, max(dp(k - 1, i - 1), dp(k, n - i)) + 1);
//     }
//     memo[k][n] = res;
//     return res;
//   }

//   vector<vector<int>> memo;

//  public:
//   int superEggDrop(int K, int N) {
//     memo = vector<vector<int>>(K + 1, vector<int>(N + 1, -1));
//     return dp(K, N);
//   }
// };

// o(knlogn)
class Solution {
  int dp(int k, int n) {
    if (k == 1) return n;
    if (n == 0) return 0;

    if (memo[k][n] != -1) return memo[k][n];
    int res = INT_MAX;
    int l = 1, r = n;
    while (l <= r) {
      int mid = l + ((r - l) >> 2);
      int a = dp(k - 1, mid - 1);
      int b = dp(k, n - mid);
      // log("a=%d,b=%d,mid=%d\n", a, b, mid);
      if (a > b) {
        r = mid - 1;
        res = min(res, a + 1);
      } else {
        l = mid + 1;
        res = min(res, b + 1);
      }
    }
    memo[k][n] = res;
    return res;
  }

  vector<vector<int>> memo;

 public:
  int superEggDrop(int K, int N) {
    memo = vector<vector<int>>(K + 1, vector<int>(N + 1, -1));
    return dp(K, N);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  log("%d\n", s.superEggDrop(2, 2));
  return 0;
}
