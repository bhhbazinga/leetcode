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

// 暴力
// class Solution {
//  public:
//   vector<int> closestDivisors(int num) {
//     int begin = sqrt(num);
//     int i = begin, j = begin + 1;
//     int num1 = num + 1;
//     int num2 = num + 2;
//     while (true) {
//       int p = i * j;
//       if (p == num1 || p == num2) return {i, j};
//       if (p < num1) {
//         ++i;
//         continue;
//       }
//       if (p > num2) {
//         --j;
//         continue;
//       }
//     }
//   }
// };

//
class Solution {
 public:
  vector<int> Help(int num) {
    int s = sqrt(num);
    while (num % s != 0) {
      --s;
    }
    return {s, num / s};
  }

  vector<int> closestDivisors(int num) {
    vector<int> res1 = Help(num + 1);
    vector<int> res2 = Help(num + 2);
    return abs(res1[0] - res1[1]) < abs(res2[0] - res2[1]) ? res1 : res2;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> res = s.closestDivisors(8);
  log("%d,%d\n", res[0], res[1]);
}