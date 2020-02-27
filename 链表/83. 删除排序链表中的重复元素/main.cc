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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (nullptr == head) return nullptr;
    
    ListNode* prev = head;
    ListNode* cur = head->next;
    while (cur != nullptr) {
      if (prev->val == cur->val) {
        prev->next = cur->next;
        cur = prev->next;
      } else {
        prev = cur;
        cur = cur->next;
      }
    }
    return head;
  }
};

int main(long argc, char const* argv[]) { return 0; }
