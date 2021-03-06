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
    vector<int> dp(n + 3, 0);
    int sum = 0;
    for (int i = n - 1; i >= 0; --i) {
      sum += stoneValue[i];
      dp[i] = sum - min({dp[i + 1], dp[i + 2], dp[i + 3]});
    }
    if (dp[0] > sum - dp[0]) return "Alice";
    if (dp[0] < sum - dp[0]) return "Bob";
    return "Tie";
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> stoneValue = {1, 2, 3, 7};
  s.stoneGameIII(stoneValue);
  return 0;
}
