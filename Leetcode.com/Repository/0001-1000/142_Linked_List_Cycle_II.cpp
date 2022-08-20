// https://leetcode.com/problems/linked-list-cycle-ii/


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// time: O(n)
// space: O(1)

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode* slow = head, *fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
        break;
    }
    
    if (!fast or !fast->next)
      return nullptr;
    
    slow = head;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    
    return slow;
  }
};