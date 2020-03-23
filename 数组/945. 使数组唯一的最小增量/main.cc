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
// class Solution {
//  public:
//   int minIncrementForUnique(vector<int>& A) {
//     unordered_map<int, int> num2cnt;
//     set<int> num_set;
//     for (int num : A) {
//       ++num2cnt[num];
//       num_set.insert(num);
//     }
//     int res = 0;
//     for (auto it = num_set.begin(); it != num_set.end(); ++it) {
//       int num = *it;
//       int add = num2cnt[num] - 1;
//       if (add > 0) {
//         num2cnt[num + 1] += add;
//         num_set.insert(num + 1);
//         res += add;
//       }
//     }
//     return res;
//   }
// };

class Solution {
  static const int kMax = 80000;
 public:
  int minIncrementForUnique(vector<int>& A) {
    vector<int> cnt(kMax, 0);
    for (int num : A) {
      ++cnt[num];
    }

    int res = 0;
    for (int i = 0; i < kMax; ++i) {
      int add = cnt[i] - 1;
      if (add > 0) {
        cnt[i + 1] += add;
        res += add;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A = {3, 2, 1, 2, 1, 7};
  log("%d\n", s.minIncrementForUnique(A));
  return 0;
}
