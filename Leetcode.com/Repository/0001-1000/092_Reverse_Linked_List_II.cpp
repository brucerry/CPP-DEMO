// https://leetcode.com/problems/reverse-linked-list-ii/


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n)
// space: O(1)
 
class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy (0, head), *cur = &dummy, *leftptr;
    for (int i = 0; i < left; i++) {
      leftptr = cur;
      cur = cur->next;
    }
    
    ListNode* prev = nullptr;
    for (int i = 0; i < right - left + 1; i++) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    
    leftptr->next->next = cur;
    leftptr->next = prev;
    
    return dummy.next;
  }
};