#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <memory>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int GetLenth(int x) {
    int len = 0;
    while (x) {
      x /= 10;
      len++;
    }
    return len;
  }

  int findNumbers(vector<int>& nums) {
    int res = 0;
    for (int num : nums) {
      res += GetLenth(num) % 2 == 0 ? 1 : 0;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  return 0;
}
