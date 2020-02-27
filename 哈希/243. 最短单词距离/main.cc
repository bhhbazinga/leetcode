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
  int shortestDistance(vector<string>& words, string word1, string word2) {
    unordered_map<string, vector<int>> s2index;
    for (int i = 0; i < words.size(); ++i) {
      s2index[words[i]].push_back(i);
    }

    vector<int> v1 = s2index[word1];
    vector<int> v2 = s2index[word2];

    int res = INT_MAX;
    for (int i = 0; i < v1.size(); ++i) {
      for (int j = 0; j < v2.size(); ++j) {
        if (abs(v1[i] - v2[j]) < res) {
          res = abs(v1[i] - v2[j]);
        }
      }
    }
    return res;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
  log("%d\n", s.shortestDistance(words, "coding", "practice"));
  return 0;
}
