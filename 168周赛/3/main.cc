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

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

class Solution {
 public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int max = 0;
    int letters = 0;

    unordered_map<string, int> substr2cnt;
    unordered_map<char, int> char2cnt;

    for (int i = 0; i < minSize; ++i) {
      ++char2cnt[s[i]];
      letters += char2cnt[s[i]] == 1 ? 1 : 0;
    }

    if (letters <= maxLetters) {
      string substr = s.substr(0, minSize);
      ++substr2cnt[substr];
    }

    for (int i = 1; i + minSize <= s.length(); ++i) {
      unordered_set<char> set;
      letters -= --char2cnt[s[i - 1]] == 0 ? 1 : 0;
      letters += ++char2cnt[s[i + minSize - 1]] == 1 ? 1 : 0;
      if (letters <= maxLetters) {
        string substr = s.substr(i, minSize);
        ++substr2cnt[substr];
        max = std::max(substr2cnt[substr], max);
      }
    }
    return max;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  log("%d\n", s.maxFreq("aababcaab", 2, 3, 4));
  return 0;
}
