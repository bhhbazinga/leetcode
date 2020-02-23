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
  int minSteps(string s, string t) {
    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());

    // int cnt = 0;
    // for (int i = 0; i < )

    unordered_map<char, int> char2cnt_s;
    unordered_map<char, int> char2cnt_t;

    for (int c : s) {
      ++char2cnt_s[c];
    }

    for (int c : t) {
      ++char2cnt_t[c];
    }

    int res = 0;
    for (auto& pair : char2cnt_s) {
      char c = pair.first;
      if (char2cnt_s[c] > char2cnt_t[c]) {
        res += (char2cnt_s[c] - char2cnt_t[c]);
        // log("%c,%d,%d\n", c, char2cnt_s[c], char2cnt_t[c]);
      }
    }

    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  log("%d\n", s.minSteps("friend", "family"));
  return 0;
}
