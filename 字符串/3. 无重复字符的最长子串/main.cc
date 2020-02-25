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
  int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0;
    int res = 0;
    unordered_map<char, int> char2index;
    while (i < s.size() && j < s.size()) {
      char c = s[j];
      if (char2index.find(c) == char2index.end() || char2index[c] < i) {
        char2index[c] = j++;
      } else {
        res = max(res, j - i);
        i = char2index[c] + 1;  // skip
      }
    }
    return max(j - i, res);
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  log("%d\n", s.lengthOfLongestSubstring(" "));
  return 0;
}
