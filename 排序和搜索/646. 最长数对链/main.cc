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
  int findLongestChain(vector<vector<int>>& pairs) {
    sort(
        pairs.begin(), pairs.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    int cur = 0;
    int cnt = 1;

    for (int i = 1; i < pairs.size(); ++i) {
      if (pairs[i][0] > pairs[cur][1]) {
        cur = i;
        ++cnt;
      }
    }
    return cnt;
  }
};

using namespace std;
int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
  log("%d\n", s.findLongestChain(pairs));
  return 0;
}
