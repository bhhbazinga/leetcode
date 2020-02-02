#include <algorithm>
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
class Solution {
 public:
  int minSetSize(vector<int>& arr) {
    unordered_map<int, int> num2count;
    for (int num : arr) {
      ++num2count[num];
    }

    vector<int> nums;
    for (auto const& pair : num2count) {
      nums.push_back(pair.first);
    }

    sort(nums.begin(), nums.end(),
         [&](int a, int b) { return num2count[a] > num2count[b]; });

    int half = arr.size() / 2;
    int cnt = 0;
    int index = 0;
    for (int num : nums) {
      ++index;
      cnt += num2count[num];
      if (cnt >= half) {
        break;
      }
    }

    return index;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  Solution s;
  vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
  log("%d\n", s.minSetSize(arr));
  return 0;
}
