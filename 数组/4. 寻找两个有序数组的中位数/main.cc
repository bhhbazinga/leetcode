#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <list>
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
// class Solution {
//  public:
//   double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
//     int m = nums1.size();
//     int n = nums2.size();
//     int len = m + n;
//     int i = 0, j = 0;
//     double prev, cur;
//     for (int k = 0; k <= len / 2; ++k) {
//       prev = cur;
//       if (i < m && (j >= n || nums1[i] <= nums2[j])) {
//         cur = nums1[i++];
//       } else {
//         cur = nums2[j++];
//       }
//     }
//     return (len & 1) == 0 ? (prev + cur) / 2 : cur;
//   }
// };

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int len = m + n;
    int k = len / 2;
    return (len & 1) == 0 ? (FindKth(nums1, 0, m - 1, nums2, 0, n - 1, k) +
                             FindKth(nums1, 0, m - 1, nums2, 0, n - 1, k + 1)) /
                                2
                          : FindKth(nums1, 0, m - 1, nums2, 0, n - 1, k + 1);
  }

  double FindKth(const vector<int>& A, int al, int ar, const vector<int>& B, int bl, int br,
                 int k) {
    int alen = ar - al + 1;
    int blen = br - bl + 1;
    if (alen == 0) return B[bl + k - 1];
    if (blen == 0) return A[al + k - 1];
    if (k == 1) return A[al] <= B[bl] ? A[al] : B[bl];
    int i = min(al + k / 2 - 1, ar);
    int j = min(bl + k / 2 - 1, br);
    // (i + 1 - al)为本次比较后消除了几个数字,下同
    return A[i] <= B[j] ? FindKth(A, i + 1, ar, B, bl, br, k - (i + 1 - al))
                        : FindKth(A, al, ar, B, j + 1, br, k - (j + 1 - bl));
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  // log("%lf\n\n", s.findMedianSortedArrays({1, 1, 3, 3}, {1, 1, 3, 3}));
  // log("%lf\n\n", s.findMedianSortedArrays({1, 2}, {3, 4}));
  // log("%lf\n\n", s.findMedianSortedArrays({4, 5}, {1, 2, 3, 6}));
  return 0;
}
