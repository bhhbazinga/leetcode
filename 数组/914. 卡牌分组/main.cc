#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
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
  int GCD(int a, int b) {
    if (a < b) swap(a, b);
    return a % b == 0 ? b : GCD(a % b, b);
  }

 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> card2cnt;
    for (int d : deck) {
      ++card2cnt[d];
    }
    int g = -1;
    for (auto& p : card2cnt) {
      g = g == -1 ? p.second : GCD(g, p.second);
    }
    return g >= 2;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  // vector<int> deck = {1,1,1,2,2,2,3,3};
  // vector<int> deck = {1,2,3,4,4,3,2,1};
  vector<int> deck = {1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
  log("%d\n", s.hasGroupsSizeX(deck));
  return 0;
}
