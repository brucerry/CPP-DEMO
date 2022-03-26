// https://leetcode.com/problems/rotate-list/



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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;

    int len = 1;
    ListNode *tail = head;
    while (tail->next) {
      len++;
      tail = tail->next;
    }

    k %= len;

    if (k == 0) return head;

    ListNode *cur = head;

    for (int i = 0; i < len - k - 1; i++) {
      cur = cur->next;
    }

    ListNode* newHead = cur->next;
    cur->next = nullptr;
    tail->next = head;

    return newHead;
  }
};