// https://leetcode.com/problems/reorder-list/



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
  void reorderList(ListNode* head) {
    ListNode* slow = head, *fast = head->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // now slow is pointing to the half of the list

    // start reversing the second half of the list

    ListNode* right = slow->next, *prev = slow->next = nullptr;
    
    while (right) {
      ListNode* next = right->next;
      right->next = prev;
      prev = right;
      right = next;
    }

    right = prev;

    ListNode* left = head;

    // left -> first node
    // right -> last node

    while (right) {
      ListNode* leftNext = left->next;
      ListNode* rightPrev = right->next;
      left->next = right;
      right->next = leftNext;
      left = leftNext;
      right = rightPrev;
    }
  }
};