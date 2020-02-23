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
  bool checkIfExist(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
      for (int j = 0 ; j < arr.size(); ++j) {
        if (i != j && (arr[i] * 2 == arr[j] || arr[j] * 2 == arr[i])) {
          // log("%d,%d\n", num1, num2);
          return true;
        }
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr = {-2, 0, 10, -19, 4, 6, -8};
  log("%d\n", s.checkIfExist(arr));
  return 0;
}
