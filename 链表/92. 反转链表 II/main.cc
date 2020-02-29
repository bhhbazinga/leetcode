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

class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ++m;
    ++n;
    ListNode* tmp_head = new ListNode(-1);
    tmp_head->next = head;
    ListNode* p = tmp_head;
    p = tmp_head;
    ListNode* pm_prev;
    ListNode* pm;
    ListNode* pn;
    ListNode* pn_next;
    for (int i = 0; i < m - 1; ++i) {
      pm_prev = p;
      p = p->next;
    }
    pm = p;

    pn = pm;
    for (int i = 0; i < n - m + 1; ++i) {
      pn = p;
      p = p->next;
    }
    pn_next = p;

    ListNode* prev = pm;
    ListNode* cur = pm->next;
    while (cur != pn_next) {
      ListNode* cur_next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = cur_next;
    }
    pm_prev->next = pn;
    pm->next = pn_next;

    head = tmp_head->next;
    delete tmp_head;
    return head;
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
  s.reverseBetween(node1, 1, 2);
  return 0;
}
