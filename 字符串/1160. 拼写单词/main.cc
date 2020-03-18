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
  int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> char2cnt;
    for (char c : chars) {
      ++char2cnt[c];
    }
    int ans = 0;
    for (string& word : words) {
      bool flag = true;
      unordered_map<char, int> cur_char2cnt;
      for (char c : word) {
        ++cur_char2cnt[c];
        if (cur_char2cnt[c] > char2cnt[c]) {
          flag = false;
          break;
        }
      }
      ans += flag ? word.size() : 0;
    }
    return ans;
  }
};
int main(long argc, char const* argv[]) { return 0; }
