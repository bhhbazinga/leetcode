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
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int dp[kMax];
    dp[0] = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
      dp[i] = dp[i - 1] ^ arr[i];
    }

    vector<int> res;
    for (int i = 0; i < queries.size(); ++i) {
      int l = queries[i][0];
      int r = queries[i][1];
      int num = l == 0 ? dp[r] : dp[r] ^ dp[l - 1];
      res.push_back(num);
    }
    return res;
  }

 private:
  enum { kMax = 3 * 10000 };
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> arr = {4, 8, 2, 10};
  vector<vector<int>> queries = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};
  vector<int> res = s.xorQueries(arr, queries);
  for (int i = 0; i < res.size(); ++i) {
    log("%d,", res[i]);
  }
  return 0;
}
