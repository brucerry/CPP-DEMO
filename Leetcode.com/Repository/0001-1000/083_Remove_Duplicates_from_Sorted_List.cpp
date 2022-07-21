// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* cur = head;
    
    while (cur) {
      while (cur->next and cur->val == cur->next->val) {
        cur->next = cur->next->next;
      }
      cur = cur->next;
    }
    
    return head;
  }
};