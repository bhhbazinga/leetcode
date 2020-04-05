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
  int numSteps(string s) {
    int step = 0;
    int i = s.size() - 1;
    while (i > 0) {
      if (s[i] == '0') {
        --i;
      } else {
        int j = i;
        // log("%d,%c\n", i, s[i]);
        while (j >= 0 && s[j] == '1') {
          s[j--] = '0';
        }
        if (j >= 0) {
          s[j] = '1';
        } else {
          s.insert(0, "1");
          ++i;
        }
      }
      ++step;
    }
    return step;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  log("%d\n", s.numSteps("1"));
  return 0;
}
