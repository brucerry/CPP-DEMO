// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// m = len of list
// time: O(m)
// space: O(1)

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);

    ListNode* left = head, *right = head, *prev = dummy;
    
    while (n--) {
      right = right->next;
    }

    while (right) {
      right = right->next;
      prev = left;
      left = left->next;
    }

    prev->next = left->next;

    return dummy->next;
  }
};