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
 public:
  string longestPrefix(string s) {
    int n = s.size();
    vector<int> next(n);
    next[0] = -1;
    for (int i = 1; i < n; ++i) {
      int j = next[i - 1];
      for (;;) {
        if (s[j + 1] == s[i]) {
          next[i] = j + 1;
          break;
        }
        if (j == -1) {
          next[i] = -1;
          break;
        }
        j = next[j];
      }
    }
    return next[n - 1] == -1 ? "" : s.substr(0, next[n - 1] + 1);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  log("%s\n", s.longestPrefix("bba").c_str());
  return 0;
}
