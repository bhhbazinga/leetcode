#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <numeric>
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
  struct Node {
    Node(char c_) : c(c_) { memset(&childs[0], 0, sizeof(childs[0]) * 26); }
    char c;
    Node* childs[26];
  };

  void dfs(Node* node, int& res, int deep) {
    bool leaf = true;
    for (Node* child : node->childs) {
      if (child != nullptr) {
        leaf = false;
        dfs(child, res, deep + 1);
      }
    }
    if (leaf) {
      res += deep + 1;
    }
  }

 public:
  int minimumLengthEncoding(vector<string>& words) {
    Node* root = new Node(0);
    for (string& w : words) {
      Node* node = root;
      for (int i = w.size() - 1; i >= 0; --i) {
        char c = w[i] - 'a';
        if (nullptr == node->childs[c]) {
          node->childs[c] = new Node(c);
        }
        node = node->childs[c];
      }
    }
    int res = 0;
    dfs(root, res, 0);
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> words = {"time", "me", "bell"};
  log("%d\n", s.minimumLengthEncoding(words));
  return 0;
}
