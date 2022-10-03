// https://leetcode.com/problems/delete-node-in-a-linked-list/


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// time: O(1)
// space: O(1)

class Solution {
public:
  void deleteNode(ListNode* node) {
    *node = *node->next;
  }
};