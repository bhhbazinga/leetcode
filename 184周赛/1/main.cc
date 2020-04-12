#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <map>
#include <memory>
#include <numeric>
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
  vector<string> stringMatching(vector<string> words) {
    vector<string> res;
    set<string> res_set;

    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < words.size(); ++j) {
        if (i != j && words[j].find(words[i]) != -1) {
          res_set.insert(words[i]);
          // log("%s\n", words[i].data());
        }
      }
    }

    for (auto it = res_set.begin(); it != res_set.end(); ++it) {
      res.push_back(*it);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  s.stringMatching({"leetcoder","leetcode","od","hamlet","am"});
  return 0;
}
