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
  string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();
    vector<int> dp(n + 1);
    dp[n] = 0;
    int sum = 0;
    for (int i = n - 1; i >= 0; --i) {
      sum += stoneValue[i];
      dp[i] = INT_MIN;
      for (int j = i; j < i + 3 && j < n; ++j) {
        dp[i] = max(dp[i], sum - dp[j + 1]);
      }
    }
    if (dp[0] > sum - dp[0]) {
      return "Alice";
    } else if (dp[0] < sum - dp[0]) {
      return "Bob";
    }
    return "Tie";
  }
};

int main(int argc, char const* argv[]) { return 0; }
