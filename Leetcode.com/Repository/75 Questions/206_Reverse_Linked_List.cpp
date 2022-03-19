// https://leetcode.com/problems/reverse-linked-list/



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n)
// space: O(1) for iterative, O(n) for recursive

class Solution {
public:

  // recursive
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;

    ListNode* newHead = head;

    if (head->next) {
      newHead = reverseList(head->next);
      head->next->next = head;
    }
    head->next = nullptr;

    return newHead;
  }

  // iterative
  // ListNode* reverseList(ListNode* head) {
  //   ListNode* cur = head, *prev = nullptr;

  //   while (cur) {
  //     ListNode* next = cur->next;
  //     cur->next = prev;
  //     prev = cur;
  //     cur = next;
  //   }

  //   return prev;
  // }
};