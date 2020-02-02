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

// 先求出整棵树的和sum
// sub_sum = 某棵子树和
// res = max {sum * sum - sub_sum}
class Solution {
 public:
  int maxProduct(TreeNode* root) {
    vector<int> sums;
    long sum = calSum(root, sums);

    long res = INT_MIN;
    for (int i = 0; i < sums.size(); ++i) {
      res = max(res, sums[i] * (sum - sums[i]));
    }
    return res % static_cast<long>(1e9 + 7);
  }

  long calSum(TreeNode* node, vector<int>& sums) {
    if (node == nullptr) return 0;

    long sum = node->val + calSum(node->left, sums) + calSum(node->right, sums);
    sums.push_back(sum);
    return sum;
  }
};

int main(int argc, char const* argv[]) {
  /* code */

  Solution s;
  return 0;
}
