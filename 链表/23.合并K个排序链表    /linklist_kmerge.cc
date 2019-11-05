#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 private:
  struct Comparator {
    bool operator()(ListNode* a, ListNode* b) const { return a->val > b->val; }
  };

 public:
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // 1. 用优先队列优化比较
    // 时间复杂度:o(Nlogk)
    // 空间复杂度:o(k)
    std::priority_queue<ListNode*, std::deque<ListNode*>, Comparator> pq;
    for (ListNode* node : lists) {
      if (node != nullptr) {
        pq.push(node);
      }
    }

    ListNode l = ListNode(-1);
    ListNode* p = &l;
    while (!pq.empty()) {
      ListNode* top = pq.top();
      pq.pop();
      p->next = top;
      p = p->next;

      if (top->next != nullptr) {
        pq.push(top->next);
      }
    }
    return l.next;

    // 2. 每次选一个最小的加入结果链表
    // 时间复杂度:o(kN)
    // 空间复杂度:o(1)
    // int min_j;
    // ListNode* min;
    // ListNode* cur;

    // for (;;) {
    //   for (int i = 0; i < lists.size(); ++i) {
    //     min = lists[0];
    //     min_j = 0;
    //     for (int j = 1; j < lists.size(); ++j) {
    //       cur = lists[j];
    //       if (min == nullptr || (cur != nullptr && cur->val < min->val)) {
    //         min = cur;
    //         min_j = j;
    //       }
    //     }

    //     p->next = min;
    //     if (min == nullptr) {
    //       return l.next;
    //     }

    //     lists[min_j] = min->next;
    //     p = p->next;
    //   }
    // }
  }
};