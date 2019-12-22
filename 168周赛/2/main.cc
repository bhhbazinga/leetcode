#include <algorithm>
#include <cassert>
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

using namespace std;

#define log(fmt, ...)                \
  do {                               \
    fprintf(stderr, fmt, __VA_ARGS__) \
  }

class Solution {
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    map<int, int> num2cnt;
    for (int num : nums) {
      if (num2cnt.find(num) == num2cnt.end()) {
        num2cnt.insert(make_pair(num, 1));
      } else {
        ++num2cnt[num];
      }
    }

    for (const auto& pair : num2cnt) {
      int num = pair.first;
      int cnt = pair.second;
      if (cnt == 0) {
        continue;
      }

      for (int next_num = num + 1; next_num < num + k; ++next_num) {
        if (num2cnt.find(next_num) == num2cnt.end()) {
          return false;
        }

        if (num2cnt[next_num] < cnt) {
          return false;
        }

        num2cnt[next_num] -= cnt;
      }
    }

    return true;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  vector<int> v = {3,3,2,2,1,1};
  Solution s;
  printf("%d\n", s.isPossibleDivide(v, 3));
  return 0;
}
