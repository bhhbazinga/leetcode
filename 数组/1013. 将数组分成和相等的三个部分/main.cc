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
  bool canThreePartsEqualSum(vector<int>& A) {
    int n = A.size();
    vector<int> sums(n, 0);
    sums[0] = A[0];
    for (int i = 1; i < n; ++i) {
      sums[i] = sums[i - 1] + A[i];
    }
    double target = sums[n - 1] / 3;
    int i;
    for (i = 0; i < n - 2; ++i) {
      if (sums[i] == target) break;
    }
    if (i >= n - 2) return false;

    int j;
    for (j = i + 1; j < n - 1; ++j) {
      if (sums[j] - sums[i] == target) break;
    }
    if (j >= n - 1) return false;

    return sums[n - 1] - sums[j] == target;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;

  vector<int> A = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
  s.canThreePartsEqualSum(A);
  return 0;
}
