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

class WordDictionary {
  static const int kCharacters = 26;

  struct Node {
    Node() : end(false) {}
    unordered_map<char, Node*> child_map;
    bool end;
  };

  Node* head_;

 public:
  /** Initialize your data structure here. */
  WordDictionary() : head_(new Node()) {}

  /** Adds a word into the data structure. */
  void addWord(std::string word) {
    Node* p = head_;
    for (char c : word) {
      int index = c - 'a';
      auto& child_map = p->child_map;
      if (child_map.find(index) == child_map.end()) {
        child_map[index] = new Node();
      }
      p = child_map[index];
    }
    p->end = true;
  }

  bool searchHelper(Node* p, string word, int i) {
    if (i >= word.size()) {
      return p->end;
    }

    char c = word[i];
    auto& child_map = p->child_map;
    if (c == '.') {
      for (auto it = child_map.begin(); it != child_map.end(); ++it) {
        if (searchHelper(it->second, word, i + 1)) {
          return true;
        }
      }
      return false;
    }

    int index = c - 'a';
    if (child_map.find(index) != child_map.end() &&
        searchHelper(child_map[index], word, i + 1)) {
      return true;
    }
    return false;
  }

  /** Returns if the word is in the data structure. A word could contain the
   * dot character '.' to represent any one letter. */
  bool search(string word) { return searchHelper(head_, word, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, char const* argv[]) {
  WordDictionary dic;

  WordDictionary* obj = new WordDictionary();
  obj->addWord("a");
  obj->addWord("ab");

  log("%d\n", obj->search("a."));

  return 0;
}
