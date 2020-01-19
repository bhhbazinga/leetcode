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

class Solution {
public:
    int maximum69Number (int num) {
      for (int i = 3; i >= 0; --i) {
        int x = num / pow(10, i);
        if (x == 0) continue;

        x = x % 10;
        // log("%d,%d\n", x, i);
        if (x == 6) {
          return num - 6 * pow(10, i) + 9 * pow(10, i);
        }
      }

      return num;
    }
};


int main(int argc, char const* argv[]) {
  /* code */

  Solution s;
  log(">>>>>>>>>%d\n", s.maximum69Number(9999));
  return 0;
}
