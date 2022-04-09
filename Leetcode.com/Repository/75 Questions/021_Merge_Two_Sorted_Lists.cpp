// https://leetcode.com/problems/merge-two-sorted-lists/



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// l1 = len of list1
// l2 = len of list2
// time: O(min(l1, l2))
// space: O(1)

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    
    while (list1 && list2) {
      if (list1->val < list2->val) {
        cur->next = list1;
        list1 = list1->next;
      }
      else {
        cur->next = list2;
        list2 = list2->next;
      }
      cur = cur->next;
    }
    
    if (list1)
      cur->next = list1;
    
    if (list2)
      cur->next = list2;
    
    return dummy.next;
  }
};