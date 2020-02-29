#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
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
  vector<int> lexicalOrder(int n) {
    vector<int> ans;
    for (int i = 1; i <= 9; ++i) {
      dfs(ans, n, i);
    }
    return ans;
  }

  void dfs(vector<int>& ans, int n, int cur) {
    if (cur > n) return;
    ans.push_back(cur);
    for (int i = 0; i <= 9; ++i) {
      dfs(ans, n, cur * 10 + i);
    }
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  auto ans = s.lexicalOrder(100);
  for (int i = 0; i < ans.size(); ++i) {
    log("%d,", ans[i]);
  }
  return 0;
}
