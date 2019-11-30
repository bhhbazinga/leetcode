#include <vector>

#include <limits>
class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    int min = __INT_MAX__;
    int profit = 0;
    for (int i = 0; i < prices.size(); ++i) {
      if (prices[i] < min) {
        min = prices[i];
      } else if (prices[i] - min > profit) {
        profit = prices[i] - min;
      }
    }
    return profit;
  }
};