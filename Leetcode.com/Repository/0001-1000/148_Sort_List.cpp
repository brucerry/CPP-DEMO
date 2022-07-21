// https://leetcode.com/problems/sort-list/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n * log(n))
// space: O(log(n))

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head or !head->next)
      return head;
    
    ListNode* leftptr = head;
    ListNode* rightptr = getMid(head);
    ListNode* tmp = rightptr->next;
    rightptr->next = nullptr;
    rightptr = tmp;
    
    leftptr = sortList(leftptr);
    rightptr = sortList(rightptr);
    
    ListNode dummy = ListNode();
    ListNode* cur = &dummy;
    while (leftptr and rightptr) {
      if (leftptr->val <= rightptr->val) {
        cur->next = leftptr;
        leftptr = leftptr->next;
      }
      else {
        cur->next = rightptr;
        rightptr = rightptr->next;
      }
      cur = cur->next;
    }
    
    if (leftptr)
      cur->next = leftptr;
    
    if (rightptr)
      cur->next = rightptr;
    
    return dummy.next;
  }
  
private:
  ListNode* getMid(ListNode* node) {
    ListNode* slow = node, *fast = node->next;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};