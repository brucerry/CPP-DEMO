// https://leetcode.com/problems/linked-list-cycle/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// time: O(n)
// space: O(1)

class Solution {
public:
  bool hasCycle(ListNode *head) {
    ListNode* slow = head, *fast = head;
    
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) return true;
    }
    
    return false;
  }
};