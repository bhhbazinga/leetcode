#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
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
  int maxJumps(vector<int>& arr, int d) {
    int res = 1;
    vector<int> dp(arr.size(), -1);
    for (int i = 0; i < arr.size(); ++i) {
      // log("%d,%d>>>>>>>>>\n", i, dfs(arr, dp, d, i));
      res = max(dfs(arr, dp, d, i), res);
    }

    return res;
  }

  int dfs(vector<int>& arr, vector<int>& dp, int d, int index) {
    if (dp[index] != -1) return dp[index];

    int res = -1;
    for (int i = index + 1; i <= index + d; ++i) {
      if (i >= arr.size()) break;

      if (arr[index] <= arr[i]) break;

      int next_len = dfs(arr, dp, d, i);
      dp[i] = next_len;
      res = max(res, next_len);
    }

    for (int i = index - 1; i >= index - d; --i) {
      if (i < 0) break;

      if (arr[index] <= arr[i]) break;

      int next_len = dfs(arr, dp, d, i);
      dp[i] = next_len;
      res = max(res, next_len);
    }

    if (res != -1) {
      return 1 + res;
    } else {
      res = 1;
    }

    dp[index] = res;

    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> arr = {6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12};
  log("%d\n", s.maxJumps(arr, 2));
  return 0;
}
