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
  vector<int> tree_;
  void Build(vector<int>& nums) {
    int n = nums.size();
    tree_.resize(2 * n);
    for (int i = n; i < 2 * n; ++i) {
      tree_[i] = nums[i - n];
    }
    for (int i = n - 1; i > 0; --i) {
      tree_[i] = tree_[i * 2] + tree_[i * 2 + 1];
    }
  }

  void Update(int i, int val) {
    int n = tree_.size() / 2;
    int p = i + n;
    int l, r;
    tree_[p] = val;
    while (p > 0) {
      if (p % 2 == 0) {
        l = p;
        r = p + 1;
      } else {
        l = p - 1;
        r = p;
      }
      tree_[p / 2] = tree_[l] + tree_[r];
      p /= 2;
    }
  }

  int Query(int i, int j) {
    int n = tree_.size() / 2;
    int l = n + i, r = n + j;
    int sum = 0;
    while (l <= r) {
      if (l % 2 != 0) {
        sum += tree_[l];
        ++l;
      }
      if (r % 2 != 1) {
        sum += tree_[r];
        --r;
      }
      l /= 2;
      r /= 2;
    }
    return sum;
  }

 public:
  NumArray(vector<int>& nums) { Build(nums); }

  void update(int i, int val) { Update(i, val); }

  int sumRange(int i, int j) { return Query(i, j); }
};
