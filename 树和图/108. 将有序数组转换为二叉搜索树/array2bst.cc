#include <vector>

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
 public:
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    return CreateTreeNode(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode* CreateTreeNode(const std::vector<int>& nums, int left_index,
                           int right_index) {
    // 先构建树根，再递归构建左子树，右子树
    if (left_index > right_index) {
      return nullptr;
    }

    int mid_index = (left_index + right_index) / 2;
    int val = nums[mid_index];
    TreeNode* root = new TreeNode(val);
    root->left = CreateTreeNode(nums, left_index, mid_index - 1);
    root->right = CreateTreeNode(nums, mid_index + 1, right_index);
    return root;
  }
};