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
    if (root == nullptr) {
      return true;
    }

    return IsMirror(root->left, root->right);
  }

 private:
  bool IsMirror(TreeNode *node1, TreeNode *node2) {
    // 左右两颗子树互为镜像，则他们的父节点相等，
    // 且左边子树的左子树与右边子树的右子树互为镜像，
    // 左边子树的右子树和右边子树的左子树互为镜像
    if (node1 == nullptr && node2 == nullptr) {
      return true;
    }

    if (node1 == nullptr || node2 == nullptr) {
      return false;
    }

    if (node1->val != node2->val) {
      return false;
    }

    if (!IsMirror(node1->left, node2->right)) {
      return false;
    }

    if (!IsMirror(node1->right, node2->left)) {
      return false;
    }

    return true;
  }
};