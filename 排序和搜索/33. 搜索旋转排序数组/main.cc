#include <algorithm>
#include <cstdio>
#include <vector>

class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    if (nums.size() < 3) {
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
          return i;
        }
      }
      return -1;
    }

    int min = FindMin(nums);
    auto min_it = nums.begin() + min;

    auto find_it = std::lower_bound(nums.begin(), min_it - 1, target);
    if (find_it != nums.end() && *find_it == target) {
      return static_cast<int>(find_it - nums.begin());
    }

    find_it = std::lower_bound(min_it, nums.end(), target);
    if (find_it != nums.end() && *find_it == target) {
      return static_cast<int>(find_it - nums.begin());
    }

    return -1;
  }

  int FindMin(const std::vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    if (nums[l] < nums[r]) {
      return 0;
    }

    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
        return mid;
      }

      if (nums[l] < nums[mid]) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return r + 1;
  }
};

int main(int argc, char const* argv[]) {
  std::vector<int> v = {2, 3, 1};
  Solution s;
  printf("%d\n", s.FindMin(v));
  return 0;
}
