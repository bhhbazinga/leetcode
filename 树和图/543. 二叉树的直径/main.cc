#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
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
  int ans;
  int GetDegree(TreeNode* node) {
    if (nullptr == node) return 0;
    int l_degree = GetDegree(node->left);
    int r_degree = GetDegree(node->right);
    ans = max(ans, l_degree + r_degree);
    return max(l_degree, r_degree) + 1;
  }

 public:
  int diameterOfBinaryTree(TreeNode* root) {
    ans = 0;
    GetDegree(root);
    return ans;
  }
};

int main(long argc, char const* argv[]) { return 0; }
