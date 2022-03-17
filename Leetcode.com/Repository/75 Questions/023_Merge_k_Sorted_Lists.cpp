// https://leetcode.com/problems/merge-k-sorted-lists/

#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// n = # of nodes in each list
// k = len of lists
// time: O(n * log(k))
// space: O(1)

class Solution {
private:
  ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
    if (right == left) return lists[left];
    
    ListNode* dummy = new ListNode();

    if (left < right) {
      int mid = left + ((right - left) >> 1);

      ListNode* node1 = mergeKLists(lists, left, mid);
      ListNode* node2 = mergeKLists(lists, mid + 1, right);
      ListNode* cur = dummy;

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
    }

    return dummy->next;
  }

public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return mergeKLists(lists, 0, lists.size() - 1);
  }
};