// https://leetcode.com/problems/insertion-sort-list/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n^2) in average, O(n) in best case
// space: O(1)

class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = head, *cur = head->next;
    
    while (cur) {
      if (prev->val <= cur->val) {
        prev = cur;
        cur = cur->next;
        continue;
      }
      
      ListNode* tmp = &dummy;
      while (cur->val > tmp->next->val)
        tmp = tmp->next;
      
      prev->next = cur->next;
      cur->next = tmp->next;
      tmp->next = cur;
      cur = prev->next;
    }
    
    return dummy.next;
  }
};