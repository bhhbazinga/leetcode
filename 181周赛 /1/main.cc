#include <algorithm>
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
class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    int n = nums.size();
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      res.insert(res.begin() + index[i], nums[i]);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { 
  return 0; }
