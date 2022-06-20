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
    
    ListNode* prev = nullptr, *cur = slow;
    while (cur) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    
    ListNode* l = head, *r = prev;
    while (r) {
      if (l->val != r->val)
        return false;
      l = l->next;
      r = r->next;
    }
    return true;
  }
};