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
  int Calculate(vector<vector<char>>& board, int x, int y) {
    int res = 0;
    for (int i = x + 1, j = y; i < 8; ++i) {
      char cur = board[i][j];
      if (cur == 'p') ++res;
      if (cur != '.') break;
    }

    for (int i = x - 1, j = y; i >= 0; --i) {
      char cur = board[i][j];
      if (cur == 'p') ++res;
      if (cur != '.') break;
    }

    for (int i = x, j = y + 1; j < 8; ++j) {
      char cur = board[i][j];
      if (cur == 'p') ++res;
      if (cur != '.') break;
    }

    for (int i = x, j = y - 1; j >= 0; --j) {
      char cur = board[i][j];
      if (cur == 'p') ++res;
      if (cur != '.') break;
    }
    return res;
  }

 public:
  int numRookCaptures(vector<vector<char>>& board) {
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (board[i][j] == 'R') {
          return Calculate(board, i, j);
        }
      }
    }
    return 0;
  }
};
int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<char>> board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                {'.', '.', '.', 'R', '.', '.', '.', 'p'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'},
                                {'.', '.', '.', '.', '.', '.', '.', '.'}};
  log("%d\n", s.numRookCaptures(board));
  return 0;
}
