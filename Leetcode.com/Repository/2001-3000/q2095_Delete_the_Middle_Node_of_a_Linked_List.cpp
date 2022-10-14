// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/


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
  ListNode* deleteMiddle(ListNode* head) {
    if (!head->next)
      return nullptr;

    ListNode* slow = head, *fast = head->next->next;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
  }
};