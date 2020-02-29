#include <algorithm>
#include <cassert>
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
  vector<int> rightSideView(TreeNode* root) {
    struct Node {
      Node(TreeNode* tree_node_, int level_)
          : tree_node(tree_node_), level(level_) {}
      TreeNode* tree_node;
      int level;
    };

    vector<int> ans;
    if (nullptr == root) return ans;
    queue<Node> q;
    q.emplace(root, 0);
    while (!q.empty()) {
      const Node& cur_node = q.front();
      TreeNode* cur_tree_node = cur_node.tree_node;
      int cur_val = cur_tree_node->val;
      int cur_level = cur_node.level;
      q.pop();

      if (cur_level < ans.size()) {
        ans[cur_level] = cur_val;
      } else {
        ans.push_back(cur_val);
      }

      if (cur_tree_node->left != nullptr) {
        q.emplace(cur_tree_node->left, cur_level + 1);
      }
      if (cur_tree_node->right != nullptr) {
        q.emplace(cur_tree_node->right, cur_level + 1);
      }
    }
    return ans;
  }
};

int main(long argc, char const* argv[]) { return 0; }
