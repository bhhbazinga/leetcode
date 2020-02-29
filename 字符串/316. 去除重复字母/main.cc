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
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> char2cnt;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      ++char2cnt[c];
    }
    stack<char> st;
    unordered_set<char> set;
    for (char c : s) {
      --char2cnt[c];
      if (set.find(c) != set.end()) continue;

      if (st.empty()) {
        st.push(c);
        set.insert(c);
        continue;
      }

      while (!st.empty()) {
        char top = st.top();
        if (c < top && char2cnt[top] >= 1) {
          st.pop();
          set.erase(top);
        } else {
          break;
        }
      }

      st.push(c);
      set.insert(c);
    }

    string res;
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  log("%s\n", s.removeDuplicateLetters("bcabc").c_str());
  log("%s\n", s.removeDuplicateLetters("cbacdcbc").c_str());
  log("%s\n", s.removeDuplicateLetters("edebbed").c_str());
  return 0;
}
