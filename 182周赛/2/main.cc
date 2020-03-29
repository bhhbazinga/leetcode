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
  int numTeams(vector<int>& rating) {
    int n = rating.size();
    if (n < 3) return 0;
    int i = 0;
    int k = i + 2;
    int res = 0;
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if ((rating[i] < rating[j] && rating[j] < rating[k]) ||
              (rating[i] > rating[j] && rating[j] > rating[k])) {
            ++res;
          }
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> rating = {1,2,3,4};
  log("%d\n", s.numTeams(rating));
  return 0;
}
