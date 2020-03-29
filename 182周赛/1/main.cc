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
 public:
  int findLucky(vector<int>& arr) {
    unordered_map<int, int> num2cnt;
    for (int num : arr) {
      ++num2cnt[num];
    }
    int res = -1;
    for (auto& [num, cnt] : num2cnt) {
      // log("%d,%d\n", num, cnt);
      if (num == cnt && num > res) {
        res = num;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr = {2,2,2,3,3};
  log("%d\n", s.findLucky(arr));
  return 0;
}
