// https://leetcode.com/problems/reverse-nodes-in-k-group/



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// n = len of list
// time: O(n)
// space: O(1)

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0, head);
    ListNode* groupPrev = &dummy;
    
    while (true) {
      ListNode* kth = groupPrev;
      
      for (int i = 0; i < k && kth; i++) {
        kth = kth->next;
      }
      
      if (!kth)
        break;
      
      ListNode* groupNext = kth->next;
      
      ListNode* prev = groupNext, *cur = groupPrev->next;
      while (cur != groupNext) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }
      
      ListNode* tmp = groupPrev->next;
      groupPrev->next = kth;
      groupPrev = tmp;
    }
    
    return dummy.next;
  }
};