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
#include <tuple>
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
  int lastRemaining(int n, int m) {
    int i = 0;
    for (int c = 2; c <= n; ++c) {
      i = (i + m) % c;
    }
    return i;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  return 0;
}
