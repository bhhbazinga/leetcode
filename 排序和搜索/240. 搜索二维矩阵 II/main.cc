#include <algorithm>
#include <cstdio>
#include <vector>

class Solution {
 public:
  bool Search(std::vector<std::vector<int>>& matrix, int target, int top_row,
              int top_col, int bottom_row, int bottom_col) {
    if (top_row == bottom_row && top_col == bottom_col) {
      return matrix[top_row][top_col] == target;
    }

		int top_row_bottom_row_half = (top_row + bottom_row) / 2;
		int top_col_bottom_col_half = (top_col + bottom_col) / 2;


    if (target >= matrix[top_row][top_col] &&
        target <=
            matrix[top_row_bottom_row_half][top_col_bottom_col_half]) {
      // top left
      if (Search(matrix, target, top_row, top_col, top_row_bottom_row_half,
                 top_col_bottom_col_half)) {
        return true;
      }
    }

    if (target >= matrix[top_row][std::min(top_col_bottom_col_half + 1,
                                           bottom_col)] &&
        target <= matrix[top_row_bottom_row_half][bottom_col]) {
      // top right
      if (Search(matrix, target, top_row,
                 std::min(top_col_bottom_col_half + 1, bottom_col),
                 top_row_bottom_row_half, bottom_col)) {
        return true;
      }
    }

    if (target >= matrix[std::min(top_row_bottom_row_half + 1, bottom_row)]
                        [top_col] &&
        target <= matrix[bottom_row][top_col_bottom_col_half]) {
      // bottom left
      if (Search(matrix, target,
                 std::min(top_row_bottom_row_half + 1, bottom_row), top_col,
                 bottom_row, top_col_bottom_col_half)) {
        return true;
      }
    }

    if (target >=
            matrix[std::min(top_row_bottom_row_half + 1, bottom_row)]
                  [std::min(top_col_bottom_col_half + 1, bottom_col)] &&
        target <= matrix[bottom_row][bottom_col]) {
      // bottom right
      if (Search(matrix, target,
                 std::min(top_row_bottom_row_half + 1, bottom_row),
                 std::min(top_col_bottom_col_half + 1, bottom_col),
                 bottom_row, bottom_col)) {
        return true;
      }
    }

    return false;
  }

  bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m <= 0) {
      return false;
    }

    int n = matrix[0].size();
    if (n <= 0) {
      return false;
    }
    return Search(matrix, target, 0, 0, m - 1, n - 1);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  std::vector<std::vector<int>> v = {{1, 2}};
  printf("%d\n", s.searchMatrix(v, 2));
  return 0;
}
