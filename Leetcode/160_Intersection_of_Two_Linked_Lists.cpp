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
      if (current1 == nullptr) current1 = head2;
      else current1 = current1->next;
      if (current2 == nullptr) current2 = head1;
      else current2 = current2->next;
    }
    return current1;
  }

  // time: O(m + n)
  // space: O(1)
  // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  //   ListNode* ans = nullptr;

  //   ListNode* currentA = headA;
  //   while (currentA != nullptr) {
  //     currentA->val *= -1;
  //     currentA = currentA->next;
  //   }

  //   ListNode* currentB = headB;
  //   while (currentB != nullptr) {
  //     if (currentB->val < 0) {
  //       ans = currentB;
  //       break;
  //     }
  //     currentB = currentB->next;
  //   }

  //   // restore list A
  //   currentA = headA;
  //   while (currentA != nullptr) {
  //     if (currentA->val < 0) currentA->val *= -1;
  //     currentA = currentA->next;
  //   }

  //   return ans;
  // }

  // time: O(m + n)
  // space: O(m)
  // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  //   unordered_set<ListNode*> nodesA;
  //   ListNode* currentA = headA;
  //   while (currentA != nullptr) {
  //     nodesA.insert(currentA);
  //     currentA = currentA->next;
  //   }

  //   ListNode* currentB = headB;
  //   while (currentB != nullptr) {
  //     if (nodesA.count(currentB)) return currentB;
  //     currentB = currentB->next;
  //   }

  //   return nullptr;
  // }
};