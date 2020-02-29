#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
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

// 超时
// class Solution {
//  public:
//   double myPow(double x, int n) {
//     double res = 1;
//     if (n < 0) {
//       x = 1 / x;
//       n = -n;
//     }
//     for (long i = 0; i < n; ++i) {
//       res *= x;
//     }
//     return res;
//   }
// };

// class Solution {
//  public:
//   double myPow(double x, int n) {
//     long N = n;
//     if (N < 0) {
//       x = 1 / x;
//       N = -N;
//     }
//     return FastPow(x, N);
//   }

//   double FastPow(double x, int n) {
//     if (0 == n) return 1.0;
//     if (1 == n) return x;
//     double half = FastPow(x, n / 2);
//     return n % 2 == 0 ? half * half : half * half * x;
//   }
// };

int main(long argc, char const* argv[]) {
  Solution s;
  log("%lf\n", s.myPow(2, 9));
  return 0;
}
