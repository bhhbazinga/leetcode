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
  string convert(string s, int numRows) {
    vector<vector<char>> res(numRows, vector<char>());
    int i = 0;
    int n = s.size();
    while (i < n) {
      int j = 0;
      while (j < numRows && i < n) {
        // log("%d,%c\n", j, s[i]);
        res[j++].push_back(s[i++]);
      }
      j = 0;
      while (j < numRows - 2 && i < n) {
        // log("%d,%c\n", numRows - 2 - j, s[i]);
        res[numRows - 2 - j++].push_back(s[i++]);
      }
    }

    string res_str;
    for (const auto& vec : res) {
      for (const auto& c : vec) {
        res_str += c;
      }
    }
    // log("%s", res_str.c_str());
    return res_str;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  s.convert("LEETCODEISHIRING", 4);
  return 0;
}
