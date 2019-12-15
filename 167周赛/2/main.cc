#include <cmath>
#include <vector>

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

  std::vector<int> sequentialDigits(int low, int high) {
    int low_len = GetLenth(low);
    int high_len = GetLenth(high);

    std::vector<int> res;
    for (int len = low_len; len <= high_len; ++len) {
      for (int i = 1; i <= 10 - len; ++i) {
        int num = i * pow(10, len - 1);
        for (int j = 1; j < len; ++j) {
          num += (i + j) * pow(10, len - j - 1);
        }
        if (num <= high && num >= low) {
          res.push_back(num);
        }
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  s.sequentialDigits(100, 300);
  return 0;
}
