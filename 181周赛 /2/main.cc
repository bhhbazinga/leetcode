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
  unordered_set<int> Helper(int num) {
    unordered_set<int> res;
    int cnt = 0;
    for (int i = 1; i <= sqrt(num); ++i) {
      if (num % i == 0) {
        res.insert(i);
        res.insert(num / i);
        if (res.size() > 4) return {};
      }
    }
    // for (int r : res) {
    //   log("%d,", r);
    // }
    return res.size() == 4 ? res : unordered_set<int>();
  }

 public:
  int sumFourDivisors(vector<int> nums) {
    int sum = 0;
    for (int num : nums) {
      unordered_set<int> res = Helper(num);
      for (int r : res) {
        sum += r;
      }
    }
    return sum;
  }
};
int main(int argc, char const* argv[]) {
  Solution s;
  s.sumFourDivisors({4});
  return 0;
}
