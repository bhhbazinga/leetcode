struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode l3 = ListNode(-1);
    ListNode* p3 = &l3;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        p3->next = l1;
        l1 = l1->next;
      } else {
        p3->next = l2;
        l2 = l2->next;
      }
      p3 = p3->next;
    }

    p3->next = l1 == nullptr ? l2 : l1;
    return l3.next;
  }
};