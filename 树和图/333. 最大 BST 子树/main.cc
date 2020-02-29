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

// class Solution {
//  public:
//   int largestBSTSubtree(TreeNode* root) {
//     unordered_map<TreeNode*, int> node2count;
//     unordered_map<TreeNode*, bool> node2valid;
//     if (Valid(root, INT_MIN, INT_MAX, node2valid))
//       return Count(root, node2count);
//     return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
//   }

//   int Count(TreeNode* p, unordered_map<TreeNode*, int>& node2count) {
//     if (nullptr == p) {
//       node2count[p] = 0;
//       return 0;
//     }
//     if (node2count.find(p) != node2count.end()) {
//       return node2count[p];
//     }
//     int count = Count(p->left, node2count) + Count(p->right, node2count) + 1;
//     node2count[p] = count;
//     return count;
//   }

//   bool Valid(TreeNode* p, int lower, int upper,
//              unordered_map<TreeNode*, bool>& node2valid) {
//     if (node2valid.find(p) != node2valid.end()) {
//       return node2valid[p];
//     }

//     if (p == nullptr) {
//       node2valid[p] = true;
//       return true;
//     }

//     if (p->val <= lower || p->val >= upper) {
//       node2valid[p] = false;
//       return false;
//     }

//     bool valid = Valid(p->left, lower, p->val, node2valid) &&
//                  Valid(p->right, p->val, upper, node2valid);
//     node2valid[p] = valid;
//     return valid;
//   }
// };

class Solution {
 public:
  int largestBSTSubtree(TreeNode* root) {
    if (Valid(root, INT_MIN, INT_MAX)) return Count(root);
    return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
  }

  int Count(TreeNode* p) {
    if (nullptr == p) return 0;
    return Count(p->left) + Count(p->right) + 1;
  }

  bool Valid(TreeNode* p, int lower, int upper) {
    if (p == nullptr) return true;
    if (p->val <= lower || p->val >= upper) return false;
    return Valid(p->left, lower, p->val) && Valid(p->right, p->val, upper);
  }
};

int main(long argc, char const* argv[]) {
  TreeNode* root = new TreeNode(1);
  TreeNode* left = new TreeNode(2);
  root->left = left;
  Solution s;
  log("%d\n", s.largestBSTSubtree(root));
  return 0;
}
