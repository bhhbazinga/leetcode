struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


#include <vector>

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    // 输出到数组中，再判断对称性
    InOrderTraverse(root, false);
    int len = inorders_.size();
    if (len <= 0) {
      return true;
    }
    
    for (int i = 0, j = len - 1; i != j; ++i, --j) {
      std::pair<int, bool> front = inorders_[i];
      std::pair<int, bool> back = inorders_[j];

      if (front.first != back.first || front.second == back.second) {
        return false;
      }
    }
    return true;
  }

 private:
  void InOrderTraverse(TreeNode *node, bool flag) {
    if (node == nullptr) {
      return;
    }

    InOrderTraverse(node->left, true);
    inorders_.emplace_back(node->val, flag);
    InOrderTraverse(node->right, false);
  }
  std::vector<std::pair<int, bool>> inorders_;
};