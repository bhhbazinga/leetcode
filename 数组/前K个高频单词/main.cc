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
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> word2cnt;
    for (auto const& word : words) {
      ++word2cnt[word];
    }

    struct Node {
      Node(const string& word_, int cnt_) : word(word_), cnt(cnt_) {}
      string word;
      int cnt;

      bool operator<(const Node& other) const {
        if (cnt != other.cnt) {
          return cnt > other.cnt;
        }
        return word < other.word;
      }
    };

    priority_queue<Node> pq;
    for (auto it = word2cnt.begin(); it != word2cnt.end(); ++it) {
      pq.emplace(it->first, it->second);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    stack<string> st;
    while (!pq.empty()) {
      st.push(pq.top().word);
      pq.pop();
    }

    vector<string> res;
    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }
    return res;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;

  vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
  vector<string> res = s.topKFrequent(words, 2);
  for (auto& s : res) {
    log("%s,", s.c_str());
  }

  return 0;
}
