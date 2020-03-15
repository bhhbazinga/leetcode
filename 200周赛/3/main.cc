#include <algorithm>
#include <climits>
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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> ans;
    traverse(root, ans);
    return build(0, ans.size() - 1, ans);
  }

  void traverse(TreeNode* root, vector<int>& ans) {
    if (nullptr == root) return;

    traverse(root->left, ans);
    ans.push_back(root->val);
    traverse(root->right, ans);
  }

  TreeNode* build(int l, int r, vector<int>& ans) {
    if (l > r) return nullptr;

    int m = (l + r) / 2;
    TreeNode* mid = new TreeNode(ans[m]);
    TreeNode* left = build(l, m - 1, ans);
    TreeNode* right = build(m + 1, r, ans);
    mid->left = left;
    mid->right = right;
    return mid;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  TreeNode* node1 = new TreeNode(1);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(3);
  TreeNode* node4 = new TreeNode(4);

  node1->right = node2;
  node2->right = node3;
  node3->right = node4;

  s.balanceBST(node1);
}