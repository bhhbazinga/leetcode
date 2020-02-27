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

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() <= 0) return "";
    int i = 0;
    while (true) {
      char c = strs[0][i];
      for (string& s : strs) {
        if (i >= s.size() || s[i] != c) {
          return strs[0].substr(0, i);
        }
      }
      ++i;
    }
    return "";
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  vector<string> strs = {"dog", "racecar", "car"};
  log("%s\n", s.longestCommonPrefix(strs).c_str());
  return 0;
}
