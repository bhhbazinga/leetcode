#include <algorithm>
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
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<int> res(mat.size());
    for (int i = 0; i < mat.size(); ++i) {
      res[i] = i;
    }

    sort(res.begin(), res.end(), [&](int a, int b) {
      int a_score = 0;
      int b_score = 0;
      for (int i = 0; i < mat[a].size(); ++i) {
        a_score += mat[a][i];
      }
      for (int i = 0; i < mat[b].size(); ++i) {
        b_score += mat[b][i];
      }
      if (a_score != b_score) return a_score < b_score;
      return a < b;
    });

    return vector<int>(res.begin(), res.begin() + k);
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 0},
                             {1, 0, 0, 0, 0},
                             {1, 1, 0, 0, 0},
                             {1, 1, 1, 1, 1}};
  vector<int> res = s.kWeakestRows(mat, 3);
  for (int i : res) {
    log("%d,", i);
  }
  return 0;
}
