#include <cmath>
#include <stack>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  int getDecimalValue(ListNode* head) {
    std::stack<int> s;
    ListNode* p = head;
    while (p) {
      s.push(p->val);
      p = p->next;
    }
    int res = 0;
    int i = 0;
    while (!s.empty()) {
      res += s.top() * pow(2, i++);
      s.pop();
    }
    return res;
  }
};