// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/


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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy, *cur = head;

    while (cur) {
      if (cur->next and cur->val == cur->next->val) {
        while (cur->next and cur->val == cur->next->val) {
          cur = cur->next;
        }
        prev->next = cur->next;
      }
      else
        prev = prev->next;
      cur = cur->next;
    }

    return dummy->next;
  }
};