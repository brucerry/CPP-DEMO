// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
  // time: O(m + n)
  // space: O(1)
  ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
    ListNode* current1 = head1;
    ListNode* current2 = head2;
    
    while (current1 != current2) {
      if (!current1) current1 = head2;
      else current1 = current1->next;
      if (!current2) current2 = head1;
      else current2 = current2->next;
    }
    return current1;
  }
};