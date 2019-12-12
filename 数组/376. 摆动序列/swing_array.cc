#include <vector>

class Solution {
 public:
  int wiggleMaxLength(std::vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.size();
    }

    if (nums.size() == 2) {
      return nums[0] == nums[1] ? 1 : 2;
    }

    if (nums.size() == 3) {
      if (nums[1] == nums[0]) {
        return nums[1] != nums[2] ? 2 : 1;
      } else {
        return (nums[1] - nums[0]) * (nums[2] - nums[1]) < 0 ? 3 : 2;
      }
    }

    nums[0] = nums[1] - nums[0];
    nums[1] = nums[2] - nums[1];
    if (nums[0] == 0) {
      nums[0] = nums[1] != 0 ? 2 : 1;
    } else {
      nums[0] = nums[1] * nums[0] < 0 ? 3 : 2;
    }

    for (int i = 3; i < nums.size(); ++i) {
      nums[i - 1] = nums[i] - nums[i - 1];
      if (nums[i - 1] == 0) {
        nums[i - 1] = nums[i - 2];
        nums[i - 2] = nums[i - 3];
      } else {
        nums[i - 2] = nums[i - 1] * nums[i - 2] < 0 || nums[i - 2] == 0
                          ? nums[i - 3] + 1
                          : nums[i - 3];
      }
    }
    return nums[nums.size() - 3];
  }
};