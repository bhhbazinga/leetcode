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
  int removePalindromeSub(string s) {
    if (s.size() == 0) return 0;

    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    return rev_s == s ? 1 : 2;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  log("%d\n", s.removePalindromeSub("abb"));
  return 0;
}
