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
  bool isValidBST(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    int min, max;
    return Valid(root, min, max);
  }

 private:
  bool Valid(TreeNode* node, int& ref_min, int& ref_max) {
    TreeNode* left = node->left;
    TreeNode* right = node->right;
    int val = node->val;

    if (left == nullptr && right == nullptr) {
      ref_min = val;
      ref_max = val;
      return true;
    }

    int lmin = INT_MAX, lmax = INT_MIN, rmin = INT_MAX, rmax = INT_MIN;
    if (left != nullptr) {
      if (!Valid(left, lmin, lmax)) {
        return false;
      }
      if (lmax >= val) {
        return false;
      }
    }

    if (right != nullptr) {
      if (!Valid(right, rmin, rmax)) {
        return false;
      }
      if (rmin <= val) {
        return false;
      }
    }

    ref_min = std::min<int>(lmin, rmin);
    ref_max = std::max<int>(lmax, rmax);
    ref_min = std::min<int>(ref_min, val);
    ref_max = std::max<int>(ref_max, val);
    return true;
  }
};