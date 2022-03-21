// https://leetcode.com/problems/merge-two-sorted-lists/



struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// l1 = len of list1
// l2 = len of list2
// time: O(min(l1, l2))
// space: O(1)

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;

    ListNode* node1 = list1;
    ListNode* node2 = list2;

    while (node1 && node2) {
      if (node1->val < node2->val) {
        cur->next = node1;
        node1 = node1->next;
      }
      else {
        cur->next = node2;
        node2 = node2->next;
      }
      cur = cur->next;
    }

    if (node1) {
      cur->next = node1;
    }

    if (node2) {
      cur->next = node2;
    }

    return dummy->next;
  }
};