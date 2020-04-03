#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define log(fmt, ...)                  \
  do {                                 \
    fprintf(stderr, fmt, __VA_ARGS__); \
  } while (0)

using namespace std;
// class Solution {
//   void QuickSort(vector<int>& nums, int l, int r) {
//     if (l >= r) return;
//     int m = rand() % (r - l + 1) + l;
//     int mid = nums[m];
//     swap(nums[r], nums[m]);
//     int i = l, j = r - 1;
//     while (i < j) {
//       while (nums[i] < mid && i < j) {
//         ++i;
//       }
//       while (nums[j] >= mid && i < j) {
//         --j;
//       }
//       swap(nums[i], nums[j]);
//     }
//     if (nums[i] >= mid) {
//       swap(nums[i], nums[r]);
//     } else {
//       ++i;
//     }
//     QuickSort(nums, l, i - 1);
//     QuickSort(nums, i + 1, r);
//   }

//  public:
//   vector<int> sortArray(vector<int>& nums) {
//     srand(time(0));
//     QuickSort(nums, 0, nums.size() - 1);
//     return nums;
//   }
// };

// class Solution {
//   vector<int> tmp;
//   void MergeSort(vector<int>& nums, int l, int r) {
//     if (l >= r) return;
//     int m = l + ((r - l) >> 2);
//     MergeSort(nums, l, m);
//     MergeSort(nums, m + 1, r);
//     int i = l, j = m + 1, k = l;
//     while (i <= m && j <= r) {
//       if (nums[i] < nums[j]) {
//         tmp[k++] = nums[i++];
//       } else {
//         tmp[k++] = nums[j++];
//       }
//     }
//     while (i <= m) {
//       tmp[k++] = nums[i++];
//     }
//     while (j <= r) {
//       tmp[k++] = nums[j++];
//     }
//     for (int k = l; k <= r; ++k) {
//       nums[k] = tmp[k];
//     }
//   }

//  public:
//   vector<int> sortArray(vector<int>& nums) {
//     tmp.resize(nums.size());
//     MergeSort(nums, 0, nums.size() - 1);
//     return nums;
//   }
// };

class Solution {
  vector<int> tmp;
  void AdjustHep(vector<int>& nums, int i, int len) {
    int tmp = nums[i];
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {
      if (k + 1 < len && nums[k + 1] > nums[k]) ++k;
      if (nums[k] > tmp) {
        nums[i] = nums[k];
        i = k;
      } else {
        break;
      }
    }
    nums[i] = tmp;
  }

  void BuildHeap(vector<int>& nums) {
    int len = nums.size();
    for (int i = len / 2 - 1; i >= 0; --i) {
      AdjustHep(nums, i, len);
    }
  }

  void HeapSort(vector<int>& nums) {
    BuildHeap(nums);
    for (int i = nums.size() - 1; i > 0; --i) {
      swap(nums[0], nums[i]);
      AdjustHep(nums, 0, i);
    }
  }

 public:
  vector<int> sortArray(vector<int>& nums) {
    HeapSort(nums);
    return nums;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {5, 2, 3, 1};
  s.sortArray(nums);
  return 0;
}
