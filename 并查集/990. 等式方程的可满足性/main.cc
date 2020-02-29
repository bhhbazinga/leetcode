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

class Solution {
 public:
  int Find(int x, vector<int>& parent) {
    int root = parent[x];
    if (root == x) return x;

    root = Find(root, parent);
    parent[x] = root;
    return root;
  }

  void Merge(int x, int y, vector<int>& parent) {
    int x_root = Find(x, parent);
    int y_root = Find(y, parent);
    parent[x_root] = y_root;
  }

  bool equationsPossible(vector<string> equations) {
    vector<int> parent(26);
    for (int i = 0; i < 26; ++i) parent[i] = i;
    for (string& equation : equations) {
      int a = equation[0] - 'a';
      int b = equation[3] - 'a';
      int e = equation[1] == '=' ? 1 : 0;
      if (e == 1) {
        Merge(a, b, parent);
      }
    }
    for (string& equation : equations) {
      int a = equation[0] - 'a';
      int b = equation[3] - 'a';
      int e = equation[1] == '=' ? 1 : 0;
      if (e == 0 && Find(a, parent) == Find(b, parent)) return false;
    }
    return true;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  log("%d\n", s.equationsPossible({"a==b", "b!=a"}));
  log("%d\n", s.equationsPossible({"b==a", "a==b"}));
  log("%d\n", s.equationsPossible({"a==b", "b==c", "a==c"}));
  log("%d\n", s.equationsPossible({"a==b", "b!=c", "c==a"}));
  log("%d\n", s.equationsPossible({"c==c", "b==d", "x!=z"}));
  return 0;
}
