// https://leetcode.com/problems/palindrome-linked-list/

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
  bool isPalindrome(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    ListNode* prev = nullptr;
    while (slow) {
      ListNode* next = slow->next;
      slow->next = prev;
      prev = slow;
      slow = next;
    }
    
    ListNode* leftptr = head, *rightptr = prev;
    while (rightptr) {
      if (leftptr->val != rightptr->val)
        return false;
      leftptr = leftptr->next;
      rightptr = rightptr->next;
    }
    
    return true;
  }
};