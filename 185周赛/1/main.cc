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
  string destCity(vector<vector<string>>& paths) {
    for (int i = 0; i < paths.size(); ++i) {
      string& dst = paths[i][1];
      bool find = true;
      for (int j = 0; j < paths.size(); ++j) {
        if (paths[j][0] == dst) {
          find = false;
          break;
        }
      }
      if (find) return dst;
    }
    return "";
  }
};

int main(int argc, char const* argv[]) { return 0; }
