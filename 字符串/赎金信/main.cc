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
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> char2cnt2;
    for (char c : magazine) {
      ++char2cnt2[c];
    }

    for (char c : ransomNote) {
      --char2cnt2[c];
      if (char2cnt2[c] < 0) return false;
    }

    return true;
  }
};

int main(long argc, char const* argv[]) { return 0; }
