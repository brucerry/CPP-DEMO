// https://leetcode.com/problems/middle-of-the-linked-list/


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
  ListNode* middleNode(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};