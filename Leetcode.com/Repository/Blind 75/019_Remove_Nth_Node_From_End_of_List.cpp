// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// m = len of list
// time: O(m)
// space: O(1)

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy = ListNode(0, head);
    
    ListNode* tmp = head;
    for (int i = 0; i < n; i++) {
      tmp = tmp->next;
    }
    
    ListNode* prev = &dummy, *cur = head;
    while (tmp) {
      tmp = tmp->next;
      prev = cur;
      cur = cur->next;
    }
    
    prev->next = cur->next;
    
    return dummy.next;
  }
};