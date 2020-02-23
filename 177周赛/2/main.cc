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


class Solution {
 public:
  int FindRoot(int x, vector<int>& parent) {
    int root = parent[x];
    if (root == x) {
      return x;
    }

    root = FindRoot(root, parent);
    parent[x] = root;
    return root;
  }

  bool validateBinaryTreeNodes(int n, vector<int>& leftChild,
                               vector<int>& rightChild) {
    vector<int> parent(n, 0);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }

    vector<bool> have_parent(n, false);
    vector<int> degree(n, 0);
    have_parent[0] = true;
    for (int i = 0; i < n; ++i) {
      int child = leftChild[i];
      if (child == -1) continue;

      if (have_parent[child]) {
        return false;
      }

      have_parent[child] = true;
      parent[child] = i;
    }

    for (int i = 0; i < n; ++i) {
      int child = rightChild[i];
      if (child == -1) continue;

      if (have_parent[child]) {
        return false;
      }

      have_parent[child] = true;
      parent[child] = i;
    }

    for (int i = 0; i < n; ++i) {
      if (FindRoot(i, parent) != 0) {
        return false;
      }
    }
    return true;
  }
};


int main(int argc, char const* argv[]) {
  Solution s;
}
