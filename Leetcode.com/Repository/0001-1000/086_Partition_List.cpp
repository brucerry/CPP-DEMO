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
    ListNode leftHead = ListNode(0), rightHead = ListNode(0);
    ListNode* leftTail = &leftHead, *rightTail = &rightHead;
    
    while (head) {
      if (head->val < x) {
        leftTail->next = head;
        leftTail = leftTail->next;
      }
      else {
        rightTail->next = head;
        rightTail = rightTail->next;
      }
      head = head->next;
    }
    
    leftTail->next = rightHead.next;
    rightTail->next = nullptr;
    
    return leftHead.next;
  }
};