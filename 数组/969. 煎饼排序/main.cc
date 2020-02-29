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

// class Solution {
//  public:
//   string GenHash(const vector<int>& nums) {
//     string s;
//     for (int num : nums) {
//       s.push_back(num);
//     }
//     return s;
//   }

//   bool CheckOrder(const vector<int>& nums) {
//     for (int i = 0; i < nums.size() - 1; ++i) {
//       if (nums[i] > nums[i + 1]) return false;
//     }
//     return true;
//   }

//   vector<int> pancakeSort(vector<int> A) {
//     struct Node {
//       Node(const vector<int>& nums_, const vector<int>& ks_ = vector<int>())
//           : nums(nums_), ks(ks_) {}
//       vector<int> nums;
//       vector<int> ks;
//     };

//     queue<Node> q;
//     unordered_set<string> vis;
//     vis.insert(GenHash(A));
//     q.emplace(A);
//     while (!q.empty()) {
//       Node& cur = q.front();
//       vector<int> cur_nums = cur.nums;
//       vector<int> cur_ks = cur.ks;
//       q.pop();
//       if (CheckOrder(cur_nums)) {
//         return cur_ks;
//       }

//       for (int k = 2; k <= cur_nums.size(); ++k) {
//         vector<int> next_nums = cur_nums;
//         vector<int> next_ks = cur_ks;
//         reverse(next_nums.begin(), next_nums.begin() + k);
//         string hash = GenHash(next_nums);
//         if (vis.find(hash) == vis.end()) {
//           vis.insert(hash);
//           next_ks.push_back(k);
//           q.emplace(next_nums, next_ks);
//         }
//       }
//     }
//     return {};
//   }
// };

class Solution {
 public:
  vector<int> pancakeSort(vector<int>& A) {
    int n = A.size();
    vector<int> ans;
    for (int i = n; i >= 1; --i) {
      int j = max_element(A.begin(), A.begin() + i) - A.begin();
      reverse(A.begin(), A.begin() + j + 1);
      reverse(A.begin(), A.begin() + i);
      ans.push_back(j + 1);
      ans.push_back(i);
      // log("%d,%d,", j + 1, i);
    }
    return ans;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  vector<int> A = {3, 2, 4, 1};
  s.pancakeSort(A);
  return 0;
}
