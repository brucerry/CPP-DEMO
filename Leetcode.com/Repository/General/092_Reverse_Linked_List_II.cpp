// https://leetcode.com/problems/reverse-linked-list-ii/


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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *leftPrev = dummy, *cur = head;

    for (int i = 1; i <= left - 1; i++) {
      leftPrev = cur;
      cur = cur->next;
    }

    // cur is now LeftNode
    // leftPrev is now prev of LeftNode

    ListNode* prev = nullptr;

    for (int i = 1; i <= right - left + 1; i++) {
      ListNode* next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    // cur is now next of RightNode
    // prev is now RightNode
    
    leftPrev->next->next = cur;
    leftPrev->next = prev;
    
    return dummy->next;
  }
};