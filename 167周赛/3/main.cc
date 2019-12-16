#include <climits>
#include <cstdio>
#include <cstring>
#include <vector>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

// 暴力
// class Solution {
//  public:
//   bool GetSum(std::vector<std::vector<int>>& mat, int m, int n, int start_i,
//               int start_j, int w, int& sum, int threshold) {
//     if (start_i + w > m || start_j + w > n) {
//       return false;
//     }

//     sum = 0;
//     for (int i = start_i; i < start_i + w; ++i) {
//       for (int j = start_j; j < start_j + w; ++j) {
//         sum += mat[i][j];
//         if (sum > threshold) {
//           return false;
//         }
//       }
//     }
//     return true;
//   }

//   int maxSideLength(std::vector<std::vector<int>>& mat, int threshold) {
//     int m = mat.size();
//     int n = mat[0].size();
//     int max_width = std::min(m, n);
//     int res = 0;

//     for (int i = 0; i < m; ++i) {
//       for (int j = 0; j < n; ++j) {
//         for (int w = 1; w <= max_width; ++w) {
//           int sum;
//           bool ok = GetSum(mat, m, n, i, j, w, sum, threshold);
//           if (ok) {
//             if (w > res) {
//               res = w;
//             }
//           } else {
//             break;
//           }
//         }
//       }
//     }

//     return res;
//   }
// };

// 前缀和+二分
const int kMaxWidth = 300;
class Solution {
 public:
  int Helper(int dp[kMaxWidth + 1][kMaxWidth + 1], int m, int n, int w,
             int threshold) {
    for (int i = 1; i <= m; ++i) {
      if (i + w - 1 > m) {
        break;
      }
      for (int j = 1; j <= n; ++j) {
        if (j + w - 1 > n) {
          break;
        }

        int sum = GetSum(dp, i, j, i + w - 1, j + w - 1);
        if (sum <= threshold) {
          return sum;
        }
      }
    }
    return INT_MAX;
  }

  int GetSum(int dp[kMaxWidth + 1][kMaxWidth + 1], int top_row, int top_col,
             int bottom_row, int bottom_col) {
    return dp[bottom_row][bottom_col] - dp[top_row - 1][bottom_col] -
           dp[bottom_row][top_col - 1] + dp[top_row - 1][top_col - 1];
  }

  int maxSideLength(std::vector<std::vector<int>>& mat, int threshold) {
    int m = mat.size();
    int n = mat[0].size();

    int dp[kMaxWidth + 1][kMaxWidth + 1];
    memset(&dp[0][0], 0, sizeof(dp[0][0]) * (kMaxWidth + 1) * (kMaxWidth + 1));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dp[i][j] =
            dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }

    int l = 1;
    int r = std::min(m, n);
    int res = 0;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      int sum = Helper(dp, m, n, mid, threshold);
      if (sum < threshold) {
        l = mid + 1;
        res = mid;
      } else if (sum > threshold) {
        r = mid - 1;
      } else {
        res = mid;
        break;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<std::vector<int>> mat = {
      {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}};
  Solution s;
  log("%d\n", s.maxSideLength(mat, 6));
  return 0;
}
