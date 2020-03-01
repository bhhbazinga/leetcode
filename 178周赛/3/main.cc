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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> targets;
  unordered_map<TreeNode*, TreeNode*> node2parent;

  bool isSubPath(ListNode* head, TreeNode* root) {
    while (head != nullptr) {
      targets.push_back(head->val);
      head = head->next;
    }
    reverse(targets.begin(), targets.end());
    return dfs(nullptr, root, 1);
  }

  bool dfs(TreeNode* parent, TreeNode* cur, int degree) {
    if (nullptr == cur) return false;
    node2parent[cur] = parent;
    if (degree >= targets.size()) {
      bool ok = true;
      TreeNode* p = cur;
      for (int i = 0; i < targets.size(); ++i) {
        if (p->val != targets[i]) {
          ok = false;
          break;
        } else {
          p = node2parent[p];
        }
      }
      if (ok) return ok;
    }
    return dfs(cur, cur->left, degree + 1) || dfs(cur, cur->right, degree + 1);
  }
};

int main(int argc, char const* argv[]) {}