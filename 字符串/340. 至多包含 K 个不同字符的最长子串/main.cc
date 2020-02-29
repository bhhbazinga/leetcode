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
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    int n = s.size();
    int res = 0;
    int i = 0, j = 0;
    unordered_map<char, int> char2cnt;
    while (i < n && j < n) {
      char c = s[j];
      ++char2cnt[c];
      if (char2cnt.size() <= k) {
        res = max(res, j - i + 1);
        // log("%d,%d\n", i, j);
        ++j;
      } else {
        --char2cnt[s[i]];
        if (char2cnt[s[i]] <= 0) {
            char2cnt.erase(s[i]);
        }
        --char2cnt[c];
        if (char2cnt[c] <= 0) {
            char2cnt.erase(c);
        }
        ++i;
      }
    }
    return res;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  // log("%d\n", s.lengthOfLongestSubstringKDistinct("eceba", 2));
  // log("%d\n", s.lengthOfLongestSubstringKDistinct("aa", 1));
  log("%d\n", s.lengthOfLongestSubstringKDistinct("bacc", 2));
  return 0;
}
