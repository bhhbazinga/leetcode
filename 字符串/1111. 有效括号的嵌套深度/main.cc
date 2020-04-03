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
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> res(seq.size(), 0);
    for (int i = 0; i < seq.size(); ++i) {
      res[i] = seq[i] == '(' ? i & 1 : (i + 1) & 1;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  s.maxDepthAfterSplit("(()())");
  s.maxDepthAfterSplit("()(())()");
  return 0;
}
