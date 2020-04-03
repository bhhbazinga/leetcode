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
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;

// class Solution {
//   static constexpr int dir[8][2] = {{0, 1},   {0, -1}, {1, 0},  {-1, 0},
//                                     {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

//  public:
//   void gameOfLife(vector<vector<int>>& board) {
//     vector<vector<int>> old_board = board;
//     int m = board.size();
//     int n = board[0].size();
//     for (int i = 0; i < m; ++i) {
//       for (int j = 0; j < n; ++j) {
//         bool live = old_board[i][j];
//         int cnt = 0;
//         for (int k = 0; k < 8; ++k) {
//           int ni = i + dir[k][0];
//           int nj = j + dir[k][1];
//           if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
//             cnt += old_board[ni][nj];
//           }
//         }
//         if (live) {
//           if (cnt < 2 || cnt > 3) board[i][j] = 0;
//         } else {
//           if (cnt == 3) board[i][j] = 1;
//         }
//       }
//     }
//   }
// };

class Solution {
  static constexpr int dir[8][2] = {{0, 1},   {0, -1}, {1, 0},  {-1, 0},
                                    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

 public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int& state = board[i][j];
        int cnt = 0;
        for (int k = 0; k < 8; ++k) {
          int ni = i + dir[k][0];
          int nj = j + dir[k][1];
          if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
            cnt += (board[ni][nj] == 1 || board[ni][nj] == -1);
          }
        }
        assert(state == 1 || state == 0);
        if (state == 1) {
          if (cnt < 2 || cnt > 3) state = -1;
        } else {
          if (cnt == 3) state = 2;
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        board[i][j] = board[i][j] > 0;
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  s.gameOfLife(board);
  return 0;
}
