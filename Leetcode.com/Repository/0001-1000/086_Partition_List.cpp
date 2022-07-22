// https://leetcode.com/problems/partition-list/


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
  ListNode* partition(ListNode* head, int x) {
    ListNode leftHead, rightHead, *l = &leftHead, *r = &rightHead;
    while (head) {
      if (head->val < x) {
        l->next = head;
        l = l->next;
      }
      else {
        r->next = head;
        r = r->next;
      }
      head = head->next;
    }
    
    l->next = rightHead.next;
    r->next = nullptr;
    
    return leftHead.next;
  }
};