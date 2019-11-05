#include <stdio.h>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 private:
  ListNode* QuickSort(ListNode* head, ListNode** ptail) {
    if (head->next == nullptr) {
      *ptail = head;
      return head;
    }

    ListNode* pivot = head;

    ListNode* left_head = nullptr;
    ListNode* left_tail = nullptr;

    ListNode* right_head = nullptr;
    ListNode* right_tail = nullptr;

    ListNode* p = head->next;
    while (p != nullptr) {
      if (p->val < pivot->val) {
        if (left_head == nullptr) {
          left_head = p;
        } else {
          left_tail->next = p;
        }
        left_tail = p;
      } else {
        if (right_head == nullptr) {
          right_head = p;
        } else {
          right_tail->next = p;
        }
        right_tail = p;
      }
      p = p->next;
    }

    // judge position of pivot
    if (left_tail == nullptr) {
      // all node greater than pivot
      left_head = pivot;
      left_tail = pivot;
    } else if (right_tail == nullptr) {
      // all node less than pivot
      right_head = pivot;
      right_tail = pivot;
    } else {
      left_tail->next = pivot;
      left_tail = pivot;
    }
    left_tail->next = nullptr;
    right_tail->next = nullptr;

    // left
    left_head = QuickSort(left_head, &left_tail);
    // right
    right_head = QuickSort(right_head, &right_tail);
    // merge
    left_tail->next = right_head;
    *ptail = right_tail;
    return left_head;
  }

 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* tail;
    return QuickSort(head, &tail);
  }
};

/*
由于题目要求空间复杂度是 O(1)，因此不能使用递归。因此这里使用 bottom-to-up 的算法来解决。

太晚了，明天讲解！

ok，归来！

bottom-to-up 的归并思路是这样的：先两个两个的 merge，完成一趟后，再 4 个4个的 merge，直到结束。举个简单的例子：[4,3,1,7,8,9,2,11,5,6].

step=1: (3->4)->(1->7)->(8->9)->(2->11)->(5->6)
step=2: (1->3->4->7)->(2->8->9->11)->(5->6)
step=4: (1->2->3->4->7->8->9->11)->5->6
step=8: (1->2->3->4->5->6->7->8->9->11)
链表里操作最难掌握的应该就是各种断链啊，然后再挂接啊。在这里，我们主要用到链表操作的两个技术：

merge(l1, l2)，双路归并，我相信这个操作大家已经非常熟练的，就不做介绍了。
cut(l, n)，可能有些同学没有听说过，它其实就是一种 split 操作，即断链操作。不过我感觉使用 cut 更准确一些，它表示，将链表 l 切掉前 n 个节点，并返回后半部分的链表头。
额外再补充一个 dummyHead 大法，已经讲过无数次了，仔细体会吧。
---

希望同学们能把双路归并和 cut 断链的代码烂记于心，以后看到类似的题目能够刷到手软。

掌握了这三大神器后，我们的 bottom-to-up 算法伪代码就十分清晰了：

current = dummy.next;
tail = dummy;
for (step = 1; step < length; step *= 2) {
	while (current) {
		// left->@->@->@->@->@->@->null
		left = current;

		// left->@->@->null   right->@->@->@->@->null
		right = cut(current, step); // 将 current 切掉前 step 个头切下来。

		// left->@->@->null   right->@->@->null   current->@->@->null
		current = cut(right, step); // 将 right 切掉前 step 个头切下来。
		
		// dummy.next -> @->@->@->@->null，最后一个节点是 tail，始终记录
		//                        ^
		//                        tail
		tail.next = merge(left, right);
		while (tail->next) tail = tail->next; // 保持 tail 为尾部
	}
}
好了，下面是比较正式的代码。

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while (p) {
            ++length;
            p = p->next;
        }
        
        for (int size = 1; size < length; size <<= 1) {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            
            while (cur) {
                auto left = cur;
                auto right = cut(left, size); // left->@->@ right->@->@->@...
                cur = cut(right, size); // left->@->@ right->@->@  cur->@->...
                
                tail->next = merge(left, right);
                while (tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
    
    ListNode* cut(ListNode* head, int n) {
        auto p = head;
        while (--n && p) {
            p = p->next;
        }
        
        if (!p) return nullptr;
        
        auto next = p->next;
        p->next = nullptr;
        return next;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                p = l1;
                l1 = l1->next;       
            } else {
                p->next = l2;
                p = l2;
                l2 = l2->next;
            }
        }
        p->next = l1 ? l1 : l2;
        return dummyHead.next;
    }
};

*/