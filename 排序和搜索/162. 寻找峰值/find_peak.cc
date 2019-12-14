#include <climits>
#include <cstdio>
#include <vector>

class Solution {
 public:
  int findPeakElement(std::vector<int>& nums) {
    return FindPeak(nums, 0, nums.size() - 1);
  }

  int FindPeak(std::vector<int>& nums, int l, int r) {
    if (l == r) {
      return l;
    }
    int mid = (l + r) / 2;
    if (nums[mid] > nums[mid + 1]) {
      return FindPeak(nums, l, mid);
    }
    return FindPeak(nums, mid + 1, r);
  }
};
