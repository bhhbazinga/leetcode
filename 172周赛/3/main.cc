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
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
      struct Node {
        Node(TreeNode* node_, TreeNode* parent_) : node(node_), parent(parent_){}
        TreeNode* node;
        TreeNode* parent;
      };

      queue<Node> q;
      q.emplace(root, nullptr);

      stack<Node> s;

      while(!q.empty()) {
        const Node& cur = q.front();
        TreeNode* node = cur.node;
        TreeNode* parent = cur.parent;
        if (node->left) {
          q.emplace(node->left, node);
        }

         if (node->right) {
          q.emplace(node->right, node);
        }

        s.push(cur);
        q.pop();
      }

      while(!s.empty()) {
        const Node& cur = s.top();
        TreeNode* node = cur.node;
        TreeNode* parent = cur.parent;

        if (!node->left && !node->right && node->val == target) {
          if (node == root) {
            return nullptr;
          }
          
          if (parent->left == node) {
            parent->left = nullptr;
          } else {
            parent->right = nullptr;
          }
          // delete node;
        }
        s.pop();
      }

    return root;
    }
};

int main(int argc, char const* argv[]) {
  /* code */

  Solution s;
  return 0;
}
