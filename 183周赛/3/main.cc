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
  string longestDiverseString(int a, int b, int c) {
    int index2cnt[3] = {a, b, c};
    string res;
    while (true) {
      int ban = -1;
      if (res.size() > 1 && res[res.size() - 1] == res[res.size() - 2]) {
        ban = res[res.size() - 1] - 'a';
      }

      int sel = -1;
      for (int i = 0; i < 3; ++i) {
        if (i == ban || index2cnt[i] == 0) continue;
        if (sel == -1 || index2cnt[i] > index2cnt[sel]) {
          sel = i;
        }
      }
      if (sel == -1) break;
      --index2cnt[sel];
      res += ('a' + sel);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  log("%s\n", s.longestDiverseString(1, 1, 7).data());
  log("%s\n", s.longestDiverseString(2, 2, 1).data());
  log("%s\n", s.longestDiverseString(7, 1, 0).data());
  return 0;
}
