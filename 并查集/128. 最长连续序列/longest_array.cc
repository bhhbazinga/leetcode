#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    /*
    并查集（比较鸡肋）
    std::unordered_map<int, int> parent;
    std::unordered_map<int, int> degree;
    std::unordered_map<int, int> size;
    std::unordered_set<int> num_set;

    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      parent[num] = num;
      degree[num] = 0;
      size[num] = 0;
      num_set.insert(num);
    }

    for (int num : num_set) {
      int pre_root;
      int next_root;
      int pre_num = num - 1;
      int next_num = num + 1;
      if (parent.find(pre_num) != parent.end()) {
        Merge(num, pre_num, parent, degree);
      }
      if (parent.find(next_num) != parent.end()) {
        Merge(num, next_num, parent, degree);
      }
    }

    int max = 0;
    for (int num : num_set) {
      int root = FindRoot(num, parent, degree);
      int root_size = ++size[root];
      if (root_size > max) {
        max = root_size;
      }
    }

    return max;*/

    std::unordered_set<int> num_set;

    for (int i = 0; i < nums.size(); ++i) {
      num_set.insert(nums[i]);
    }

    int max = 0;
    for (int num : num_set) {
      int cur = num;
      int cur_max = 1;
      if (num_set.find(num - 1) != num_set.end()) {
        continue;
      }

      while (num_set.find(++cur) != num_set.end()) {
        ++cur_max;
      }

      max = std::max(max, cur_max);
    }

    return max;
  }

 private:
  int FindRoot(int x, std::unordered_map<int, int>& parent,
               std::unordered_map<int, int>& degree) {
    int root = parent[x];
    if (root == x) {
      return x;
    }

    root = FindRoot(root, parent, degree);
    parent[x] = root;
    degree[root] = 1;
    return root;
  }

  void Merge(int x, int y, std::unordered_map<int, int>& parent,
             std::unordered_map<int, int>& degree) {
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
