#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
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

// class Solution {
//  public:
//   ListNode* reverseList(ListNode* head) {
//     ListNode* new_head;
//     reverse(nullptr, head, &new_head);
//     return new_head;
//   }

//   void reverse(ListNode* prev, ListNode* cur, ListNode** new_head) {
//     if (nullptr == cur) {
//       *new_head = prev;
//       return;
//     }

//     reverse(cur, cur->next, new_head);
//     cur->next = prev;
//   }
// };

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (nullptr == head || nullptr == head->next) return head;
    ListNode* p = reverseList(head->next);
    head->next->next = head;
    return p;
  }
};

int main(long argc, char const* argv[]) {
  Solution s;
  // ListNode* node1 = new ListNode(1);
  // ListNode* node2 = new ListNode(2);
  // ListNode* node3 = new ListNode(3);
  // ListNode* node4 = new ListNode(4);
  // ListNode* node5 = new ListNode(5);
  // node1->next = node2;
  // node2->next = node3;
  // node3->next = node4;
  // node4->next = node5;

  ListNode* node1 = new ListNode(3);
  ListNode* node2 = new ListNode(5);
  node1->next = node2;
  // s.reverseBetween(node1, 1, 2);
  return 0;
}
