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
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int i = 0;
    int cnt = 0;
    while (i < flowerbed.size()) {
      if (flowerbed[i] == 0) {
        if (i == 0) {
          if (i + 1 >= flowerbed.size() || flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            ++cnt;
          }
        } else if (i == flowerbed.size() - 1) {
          if (flowerbed[flowerbed.size() - 2] == 0) {
            flowerbed[i] = 1;
            ++cnt;
          }
        } else {
          if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
            flowerbed[i] = 1;
            ++cnt;
          }
        }
      }
      if (cnt >= n) return true;
      ++i;
    }
    return cnt >= n;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  vector<int> flowerbed = {1, 0, 0, 0, 0, 1};
  log("%d\n", s.canPlaceFlowers(flowerbed, 2));
  return 0;
}
