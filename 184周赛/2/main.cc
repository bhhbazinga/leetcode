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
  vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> P(m + 1);
    for (int i = 1; i <= m; ++i) {
      P[i] = i;
    }
    vector<int> res;
    for (int i = 0; i < queries.size(); ++i) {
      int q = queries[i];
      for (int j = 1; j <= m; ++j) {
        if (q == P[j]) {
          res.push_back(j - 1);
          P.erase(P.begin()  + j);
          P.insert(P.begin() + 1, q);
          // log("%d\n", j - 1);
          break;
        }
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> queries = {4,1,2,2};
  s.processQueries(queries, 4);
  return 0;
}
