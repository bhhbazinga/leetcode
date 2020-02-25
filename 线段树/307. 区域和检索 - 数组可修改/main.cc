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

class NumArray {
 private:
  vector<int> segment_tree_;
  void Build(vector<int>& nums) {
    int n = nums.size();
    segment_tree_.resize(2 * n);
    for (int i = n; i < 2 * n; ++i) {
      segment_tree_[i] = nums[i];
    }

    
  }
 public:
  NumArray(vector<int>& nums) {
    Build(nums);
  }

  void update(int i, int val) {}

  int sumRange(int i, int j) {}
};