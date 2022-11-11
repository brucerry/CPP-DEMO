// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/


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
  int getDecimalValue(ListNode* head) {
    int result = 0;
    while (head) {
      result = (result << 1) | head->val;
      head = head->next;
    }
    return result;
  }
};