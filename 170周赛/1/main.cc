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
  string freqAlphabets(string s) {
    string res;
    for (int i = 0; i < s.length();) {
      log("%d\n", i);
      char c;
      if (i + 2 < s.length() && s[i + 2] == '#') {
        c = atoi(s.substr(i, 2).c_str()) - 10 + 'j';
        i += 3;
      } else {
        c = atoi(s.substr(i, 1).c_str()) + -1 + 'a';
        ++i;
      }
      res += c;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  log("%s\n", s.freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#").c_str());
  return 0;
}
