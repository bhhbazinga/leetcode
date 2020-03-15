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
#include <cmath>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;

class Solution {
 public:
  int GetMax(vector<vector<int>>& matrix, int j) {
    int res = INT_MIN;
    for (int i = 0; i < matrix.size(); ++i) {
      res = max(res, matrix[i][j]);
    }
    return res;
  }

  int GetMin(vector<vector<int>>& matrix, int i) {
    int res = INT_MAX;
    for (int j = 0; j < matrix[i].size(); ++j) {
      res = min(res, matrix[i][j]);
    }
    return res;
  }

  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> ans;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        int min_i = GetMin(matrix, i);
        int max_j = GetMax(matrix, j);
        if (min_i == max_j) {
          ans.push_back(min_i);
          // log(">>>>>>>>>>>>%d\n", min_i);
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
  s.luckyNumbers(matrix);
  return 0;
}
