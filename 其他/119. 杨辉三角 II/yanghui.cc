#include <cstdio>
#include <unordered_map>
#include <vector>

// 用这种解法会溢出
// class Solution {
//  public:
//   std::vector<int> getRow(int rowIndex) {
//     int n = rowIndex;
//     std::vector<int> res;
//     res.resize(n + 1);
//     for (int i = 0; i <= n / 2; ++i) {
//       res[i] = Cnm(i, n);
//     }

//     for (int i = 0, j = res.size() - 1; i < j; ++i, --j) {
//       res[j] = res[i];
//     }

//     return res;
//   }
//  private:
//   unsigned long Cnm(unsigned long m, unsigned long n) { return Anm(m, n) /
//   Anm(m, m); }

//   unsigned long Anm(unsigned long m, unsigned long n) {
//     if (m == 0) {
//       return 1;
//     }

//     unsigned long res = n;
//     for (unsigned long i = 0; i < m - 1; ++i) {
//       res *= (--n);
//     }
//     return res;
//   }
// };

// c(i,n) = (n!) / i! * (n - i)!
// factor = c(i,n) / c(i - 1, n)
class Solution {
 public:
  std::vector<int> getRow(int rowIndex) {
    int n = rowIndex;
    std::vector<int> res;
    res.resize(n + 1);
    long cur = res[0] = 1;
    for (int i = 1; i <= n / 2; ++i) {
      cur = cur * (n - i + 1) / i;
      res[i] = cur;
    }

    for (int i = 0, j = res.size() - 1; i < j; ++i, --j) {
      res[j] = res[i];
    }

    return res;
  }
};