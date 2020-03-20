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
// class Solution {
//  public:
//   vector<int> getLeastNumbers(vector<int>& arr, int k) {
//     priority_queue<int> pq;
//     for (int a : arr) {
//       pq.push(a);
//       if (pq.size() > k) {
//         pq.pop();
//       }
//     }

//     stack<int> res_s;
//     while (!pq.empty()) {
//       res_s.push(pq.top());
//       pq.pop();
//     }
//     vector<int> res;
//     while (!res_s.empty()) {
//       res.push_back(res_s.top());
//       res_s.pop();
//     }
//     return res;
//   }
// };

class Solution {
 public:
  int Partition(vector<int>& arr, int l, int r) {
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

  void FindKth(vector<int>& arr, int l, int r, int k) {
    int m = Partition(arr, l, r);
    if (k == m) {
      return;
    } else if (k < m) {
      FindKth(arr, l, m - 1, k);
    } else {
      FindKth(arr, m + 1, r, k);
    }
  }

  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (k == 0 || arr.size() <= 0) return {};
    vector<int> res(k);
    FindKth(arr, 0, arr.size() - 1, k - 1);
    for (int i = 0; i < k; ++i) {
      res[i] = arr[i];
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr = {0, 0, 0, 2, 0, 5};
  s.getLeastNumbers(arr, 0);
  return 0;
}
