// https://leetcode.com/problems/swap-nodes-in-pairs/


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
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy, *cur = head;
    while (cur and cur->next) {
      prev->next = cur->next;

      ListNode* tmp = cur->next->next;
      cur->next->next = cur;
      cur->next = tmp;

      prev = cur;
      cur = cur->next;
    }
    return dummy->next;
  }
};