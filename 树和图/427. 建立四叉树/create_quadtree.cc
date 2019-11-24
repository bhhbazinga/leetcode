#include <cstdio>
#include <vector>

#define Log(fmt, ...)                                                    \
  fprintf(stderr, "%s:%d:%s(): " fmt "\n", __FILE__, __LINE__, __func__, \
          __VA_ARGS__);

// Definition for a QuadTree node.
class Node {
 public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;

  Node() {}

  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
       Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution {
 public:
  Node* construct(std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    return CreateNode(grid, 0, 0, n - 1, n - 1);
  }

 private:
  Node* CreateNode(const std::vector<std::vector<int>>& grid, int top_x,
                   int top_y, int bottom_x, int bottom_y) {
    // 剪枝，否则耗时很高
    if (IsLeaf(grid, top_x, top_y, bottom_x, bottom_y)) {
      return new Node(grid[top_y][top_x], true, nullptr, nullptr, nullptr,
                      nullptr);
    }

    Node* top_left = CreateNode(grid, top_x, top_y, (top_x + bottom_x) / 2,
                                (top_y + bottom_y) / 2);
    Node* top_right = CreateNode(grid, (top_x + bottom_x) / 2 + 1, top_y,
                                 bottom_x, (top_y + bottom_y) / 2);
    Node* bottom_left = CreateNode(grid, top_x, (top_y + bottom_y) / 2 + 1,
                                   (top_x + bottom_x) / 2, bottom_y);
    Node* bottom_right =
        CreateNode(grid, (top_x + bottom_x) / 2 + 1, (top_y + bottom_y) / 2 + 1,
                   bottom_x, bottom_y);
    bool isLeaf =
        top_left->isLeaf && top_right->isLeaf && bottom_left->isLeaf &&
        bottom_right->isLeaf && top_left->val == top_right->val &&
        top_left->val == bottom_left->val && top_left->val == bottom_right->val;
    bool val = isLeaf ? top_left->val : '*';
    return new Node(val, isLeaf, top_left, top_right, bottom_left,
                    bottom_right);
  }

  bool IsLeaf(const std::vector<std::vector<int>>& grid, int top_x, int top_y,
              int bottom_x, int bottom_y) {
    bool val = grid[top_y][top_x];
    for (int i = top_y; i <= bottom_y; ++i) {
      for (int j = top_x; j <= bottom_x; ++j) {
        if (grid[i][j] != val) {
          return false;
        }
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  std::vector<std::vector<int>> v = {{1, 0}, {1, 1}};
  s.construct(v);
  return 0;
}
