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
 private:
  // 超时
  // bool Check(long k, long h, vector<int>& piles) {
  //   priority_queue<long> pq;
  //   for (long i = 0; i < piles.size(); ++i) {
  //     pq.push(piles[i]);
  //   }

  //   while (!pq.empty()) {
  //     if (h <= 0) return false;
  //     long top = pq.top();
  //     pq.pop();
  //     if (top > k) {
  //       pq.push(top - k);
  //     }
  //     --h;
  //   }
  //   return true;
  // }

  bool Check(long k, long h, vector<int>& piles) {
    int time = 0;
    for (int num : piles) {
      time += (num - 1) / k + 1;
      if (time > h) return false;
    }
    return true;
  }

 public:
  long minEatingSpeed(vector<int>& piles, long H) {
    long max_k = LONG_MIN;
    long min_k;
    long total = 0;
    for (long i = 0; i < piles.size(); ++i) {
      max_k = max(max_k, static_cast<long>(piles[i]));
      total += piles[i];
    }
    min_k = (total - 1) / H + 1;

    long l = min_k, r = max_k;
    long res = max_k;
    while (l <= r) {
      long mid = l + (r - l) / 2;
      log("%d,%d,%d\n", mid, l, r);
      if (Check(mid, H, piles)) {
        res = min(res, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return res;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  vector<int> piles = {5};
  log("%d\n", s.minEatingSpeed(piles, 10));
  return 0;
}
