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
  string rankTeams(vector<string> votes) {
    int n = votes[0].size();
    unordered_map<char, vector<int>> char2tickets;
    for (auto& s : votes[0]) {
      char2tickets[s] = vector<int>(n, 0);
    }
    for (auto& s : votes) {
      for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        ++char2tickets[c][i];
      }
    }
    vector<char> ranks;
    for (auto it = char2tickets.begin(); it != char2tickets.end(); ++it) {
      ranks.push_back(it->first);
    }
    sort(ranks.begin(), ranks.end(), [&](char a, char b) {
      for (int i = 0; i < n; ++i) {
        if (char2tickets[a][i] != char2tickets[b][i]) {
          return char2tickets[a][i] > char2tickets[b][i];
        }
      }

      return a < b;
    });
    string res;
    for (char c : ranks) {
      res.push_back(c);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  log("%s\n", s.rankTeams({"ABC", "ACB", "ABC", "ACB", "ACB"}).c_str());
  log("%s\n", s.rankTeams({"WXYZ", "XYZW"}).c_str());
  log("%s\n", s.rankTeams({"ZMNAGUEDSJYLBOPHRQICWFXTVK"}).c_str());
  log("%s\n", s.rankTeams({"BCA", "CAB", "CBA", "ABC", "ACB", "BAC"}).c_str());
  return 0;
}
