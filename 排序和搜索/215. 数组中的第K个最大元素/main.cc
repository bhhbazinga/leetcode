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

class Solution {
  int RandomRange(int l, int r) { return rand() % (r - l + 1) + l; }

  int Partition(vector<int>& arr, int l, int r) {
    int rand_index = RandomRange(l, r);
    swap(arr[rand_index], arr[r]);
    int mid = arr[r];
    int i = l, j = r - 1;
    while (i < j) {
      while (arr[i] < mid && i < j) {
        ++i;
      }
      while (arr[j] >= mid && i < j) {
        --j;
      }
      swap(arr[i], arr[j]);
    }
    if (arr[i] >= mid)
      swap(arr[i], arr[r]);
    else
      ++i;
    return i;
  }

  int FindKth(vector<int>& arr, int l, int r, int k) {
    int m = Partition(arr, l, r);
    if (k == m) {
      return arr[k];
    } else if (k < m) {
      return FindKth(arr, l, m - 1, k);
    } else {
      return FindKth(arr, m + 1, r, k);
    }
  }

 public:
  int findKthLargest(vector<int>& nums, int k) {
    srand(time(nullptr));
    int n = nums.size();
    return FindKth(nums, 0, n - 1, n - k);
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  log("%d\n", s.findKthLargest(nums, 2));
  return 0;
}
