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
    if (!k or !head)
      return head;
    
    int len = 1;
    ListNode* tail = head;
    while (tail->next) {
      tail = tail->next;
      len++;
    }
    
    k %= len;
    
    if (!k)
      return head;
    
    ListNode* prev = nullptr, *cur = head;
    
    for (int i = 0; i < len - k; i++) {
      prev = cur;
      cur = cur->next;
    }
    
    prev->next = nullptr;
    tail->next = head;
    
    return cur;
  }
};