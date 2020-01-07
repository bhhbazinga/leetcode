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

// 自顶向下记忆化dp
// class Solution {
//  public:
//   int coinChange(vector<int>& coins, int amount) {
//     vector<int> record(amount + 1, -1);
//     int res = dp(coins, amount, record);
//     return res == INT_MAX ? -1 : res;
//   }

//   int dp(vector<int>& coins, int amount, vector<int>& record) {
//     if (record[amount] != -1) {
//       return record[amount];
//     }

//     if (amount == 0) {
//       return 0;
//     }

//     int res = INT_MAX;

//     for (int i = 0; i < coins.size(); ++i) {
//       int value = coins[i];
//       if (value > amount) {
//         continue;
//       }

//       int sub_value = amount - value;
//       int sub_count = dp(coins, sub_value, record);
//       record[sub_value] = sub_count;
//       if (sub_count == INT_MAX) {
//         continue;
//       }

//       res = min(res, sub_count + 1);
//     }

//     return res;
//   }
// };

// 自底向上dp
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    sort(coins.begin(), coins.end());
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
      int res = INT_MAX;
      for (int j = 0; j < coins.size(); ++j) {
        int value = coins[j];
        if (value > i) {
          break;
        }
        int sub = dp[i - value];
        if (sub != INT_MAX) {
          dp[i] = min(dp[i], sub + 1);
        }
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> coins = {1, 2, 5};

  log("%d\n", s.coinChange(coins, 11));
  return 0;
}
