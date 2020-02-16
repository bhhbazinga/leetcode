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

class ProductOfNumbers {
 public:
  vector<int> nums;
  ProductOfNumbers() {}

  void add(int num) { nums.push_back(num); }

  int getProduct(int k) {
    int res = 1;
    for (int i = nums.size() - 1; i >= nums.size() - k && i>=0; --i) {
      res *= nums[i];
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  ProductOfNumbers productOfNumbers = ProductOfNumbers();
  productOfNumbers.add(3);  // [3]
  productOfNumbers.add(0);  // [3,0]
  productOfNumbers.add(2);  // [3,0,2]
  productOfNumbers.add(5);  // [3,0,2,5]
  productOfNumbers.add(4);  // [3,0,2,5,4]
  log("%d\n", productOfNumbers.getProduct(2));  // 返回 20 。最后 2 个数字的乘积是 5 * 4 = 20
  // productOfNumbers.getProduct(
  //     3);  // 返回 40 。最后 3 个数字的乘积是 2 * 5 * 4 = 40
  // productOfNumbers.getProduct(
  //     4);  // 返回  0 。最后 4 个数字的乘积是 0 * 2 * 5 * 4 = 0
  // productOfNumbers.add(8);  // [3,0,2,5,4,8]
  // productOfNumbers.getProduct(2);  // 返回 32 。最后 2 个数字的乘积是 4 * 8 = 32
  return 0;
}
