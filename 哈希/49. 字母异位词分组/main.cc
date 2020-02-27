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

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> s2ss;
    for (auto& s : strs) {
      string tmp = s;
      sort(tmp.begin(), tmp.end());
      s2ss[tmp].push_back(s);
    }
    vector<vector<string>> res;
    for (auto& pair : s2ss) {
      res.push_back(pair.second);
    }
    return res;
  }
};

int main(long argc, char const* argv[]) { return 0; }
