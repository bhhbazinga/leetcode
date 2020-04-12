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
  string match[6] = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
  string rep[6] = {"\"", "\'", "&", ">", "<", "/"};

 public:
  string entityParser(string text) {
    for (int i = 0; i < 6; ++i) {
      int index = 0;
      index = text.find(match[i]);
      while (index != -1) {
        text.replace(index, match[i].size(), rep[i]);
        index = text.find(match[i], index);
      }
    }
    // log("%s\n", text.data());
    return text;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  s.entityParser("and I quote: &quot;...&quot;");
  return 0;
}
