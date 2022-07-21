// https://leetcode.com/problems/add-two-numbers/


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// m = len of l1 list
// n = len of l2 list
// time: O(max(m, n))
// space: O(max(m, n))

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy = ListNode(), *cur = &dummy;
    int carry = 0;
    
    while (l1 or l2 or carry) {
      int val1 = l1 ? l1->val : 0;
      int val2 = l2 ? l2->val : 0;
      int sum = val1 + val2 + carry;
      int val = sum % 10;
      carry = sum / 10;
      
      cur->next = new ListNode(val);
      
      cur = cur->next;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    
    return dummy.next;
  }
};