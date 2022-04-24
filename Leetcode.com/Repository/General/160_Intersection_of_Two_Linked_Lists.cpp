// https://leetcode.com/problems/intersection-of-two-linked-lists/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// m = len of listA
// n = len of listB
// time: O(m + n)
// space: O(1)

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* curA = headA, *curB = headB;
    
    while (curA != curB) {
      curA = curA ? curA->next : headB;
      curB = curB ? curB->next : headA;
    }
    
    return curA;
  }
};