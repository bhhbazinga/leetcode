struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <algorithm>
#include <climits>

class Solution {
 public:
  bool isValidBST(TreeNode* root) { return Valid(root, LONG_MIN, LONG_MAX); }

 private:
  bool Valid(TreeNode* node, long lower, long upper) {
    // 思想是当前结点需在lower-upper区间中
    if (node == nullptr) {
      return true;
    }

    int val = node->val;
    if (val <= lower || val >= upper) {
      return false;
    }

    if (!Valid(node->left, lower, val) || !Valid(node->right, val, upper)) {
      return false;
    }

    return true;
  }
};