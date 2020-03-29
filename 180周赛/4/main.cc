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

// class Solution {
//  public:
//   int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
//                      int k) {
//     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
//     vector<vector<int>> sum(n + 1, vector<int>(k + 1, 0));
//     vector<vector<int>> efficiency(n + 1, vector<int>(k + 1, 0));

//     for (int j = 1; j <= k; ++j) {
//       for (int i = j; i <= n; ++i) {
//       }
//     }

//     return dp[n][k];
//   }
// };

class Solution {
 public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,
                     int k) {
    vector<int> sorteds(n);
    for (int i = 0; i < n; ++i) {
      sorteds[i] = i;
    }
    sort(sorteds.begin(), sorteds.end(),
         [&](int a, int b) { return efficiency[a] > efficiency[b]; });
    priority_queue<int, vector<int>, greater<int>> pq;
    long sum = 0;
    long res = LONG_MIN;
    for (int i = 0; i < n; ++i) {
      int j = sorteds[i];
      int s = speed[j];
      int e = efficiency[j];
      sum += s;
      pq.push(s);
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }
      res = max(res, e * sum);
    }
    // log("%d\n", res);
    return res % static_cast<long>(1e9 + 7);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int n = 6;
  vector<int> speed = {2, 10, 3, 1, 5, 8};
  vector<int> efficiency = {5, 4, 3, 9, 7, 2};
  int k = 2;
  s.maxPerformance(6, speed, efficiency, k);
  return 0;
}
