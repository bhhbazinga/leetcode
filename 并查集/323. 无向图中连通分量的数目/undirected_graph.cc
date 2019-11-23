#include <memory.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int countComponents(int n, std::vector<std::vector<int>>& edges) {
    int* parent = new int[n];
    int* degree = new int[n];

    // init each union-find-set
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      degree[i] = 0;
    }

    for (int i = 0; i < edges.size(); ++i) {
      int x = edges[i][0];
      int y = edges[i][1];
      Merge(x, y, parent, degree);
    }

    std::unordered_set<int> root_set;
    for (int i = 0; i < n; ++i) {
      int root = FindRoot(i, parent, degree);
      root_set.insert(root);
    }

    delete[] parent;
    delete[] degree;
    return root_set.size();
  }

 private:
  int FindRoot(int x, int* parent, int* degree) {
    int root = parent[x];
    if (root == x) {
      return x;
    }

    root = FindRoot(root, parent, degree);
    parent[x] = root;
    degree[root] = 1;
    return root;
  }

  void Merge(int x, int y, int* parent, int* degree) {
    int x_root = FindRoot(x, parent, degree);
    int y_root = FindRoot(y, parent, degree);
    if (x_root == y_root) {
      return;
    }

    // select less degree tree merge to another
    int x_root_degree = degree[x_root];
    int y_root_degree = degree[y_root];
    if (x_root_degree > y_root_degree) {
      parent[y_root] = x_root;
    } else if (x_root_degree < y_root_degree) {
      parent[x_root] = y_root;
    } else {
      parent[x_root] = y_root;
      ++degree[x_root];
    }
  }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> v = {{0, 1}, {0, 2}, {1, 2}};
  s.countComponents(4, v);
}