#include <algorithm>
#include <vector>
#include <random>

class Solution {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    return FindKthLargest(nums, 0, nums.size() - 1, k);
  }

 private:
  int FindKthLargest(std::vector<int>& nums, int l, int r, int k) {
    int mid_i = random() % (r - l + 1) + l;
    std::swap(nums[mid_i], nums[r]);
    int mid = nums[r];
    int i = l;
    int j = r - 1;
    while (i < j) {
      while (nums[i] < mid && i < j) {
        ++i;
      }

      while (nums[j] >= mid && i < j) {
        --j;
      }

      std::swap(nums[i], nums[j]);
    }

    if (nums[i] >= nums[r]) {
      std::swap(nums[i], nums[r]);

      int ge = r - i;
      if (ge == k - 1) {
        return nums[i];
      }

      if (ge > k - 1) {
        return FindKthLargest(nums, i + 1, r, k);
      }

      return FindKthLargest(nums, l, i - 1, k - (ge + 1));
    } else {
      if (k == 1) {
        return nums[r];
      } else {
        return FindKthLargest(nums, l, r - 1, k - 1);
      }
    }
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  std::vector<int> v = {1, 2};
  s.findKthLargest(v, 1);
  return 0;
}
