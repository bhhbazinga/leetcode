#include <cstdio>
#include <vector>

#include <algorithm>

class Solution {
 public:
  // std::vector<int> searchRange(std::vector<int>& nums, int target) {
  //   int n = nums.size();
  //   int l = FindLastLess(nums, 0, n - 1, target);
  //   int r = FindFirstGreator(nums, 0, n - 1, target);
  //   if (l + 1 >= n || r - 1 < 0) {
  //     return {-1, -1};
  //   }

  //   if (nums[l + 1] == target && nums[r - 1] == target) {
  //     return {l + 1, r - 1};
  //   }

  //   return {-1, -1};
  // }

  // int FindLastLess(std::vector<int>& nums, int l, int r, int target) {
  //   if (l > r) {
  //     return r;
  //   }
  //   int mid = (l + r) / 2;
  //   if (nums[mid] < target) {
  //     if (mid + 1 < nums.size() && nums[mid + 1] == target) {
  //       return mid;
  //     }
  //     return FindLastLess(nums, mid + 1, r, target);
  //   } else {
  //     return FindLastLess(nums, l, mid - 1, target);
  //   }
  // }

  // int FindFirstGreator(std::vector<int>& nums, int l, int r, int target) {
  //   if (l > r) {
  //     return l;
  //   }

  //   int mid = (l + r) / 2;
  //   if (nums[mid] > target) {
  //     if (mid - 1 >= 0 && nums[mid - 1] == target) {
  //       return mid;
  //     }
  //     return FindFirstGreator(nums, l, mid - 1, target);
  //   } else {
  //     return FindFirstGreator(nums, mid + 1, r, target);
  //   }
  // }

  std::vector<int> searchRange(std::vector<int>& nums, int target) {
    auto lower = std::lower_bound(nums.begin(), nums.end(), target);
    if (lower == nums.end() || *lower != target) {
      return {-1, -1};
    }

    auto upper = std::upper_bound(nums.begin(), nums.end(), target);

    return {static_cast<int>(lower - nums.begin()),
            static_cast<int>(upper - nums.begin() - 1)};
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  std::vector<int> v = {5, 7, 7, 8, 8, 10};
  s.searchRange(v, 6);
}
