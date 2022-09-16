// https://leetcode.com/problems/odd-even-linked-list/


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
  ListNode* oddEvenList(ListNode* head) {
    if (!head)
      return head;
    
    ListNode* odd = head, *even = head->next, *evenHead = even;
    while (even and even->next) {
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }
    
    odd->next = evenHead;
    return head;
  }
};