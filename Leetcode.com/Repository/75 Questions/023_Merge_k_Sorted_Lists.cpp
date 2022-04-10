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
  ListNode* merge2Lists(vector<ListNode*>& lists, ListNode* leftNode, ListNode* rightNode) {    
    ListNode dummy, *cur = &dummy;

    while (leftNode && rightNode) {
      if (leftNode->val < rightNode->val) {
        cur->next = leftNode;
        leftNode = leftNode->next;
      }
      else {
        cur->next = rightNode;
        rightNode = rightNode->next;
      }
      cur = cur->next;
    }

    if (leftNode)
      cur->next = leftNode;

    if (rightNode)
      cur->next = rightNode;
    
    return dummy.next;
  }
  
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int interval = 1;

    while (interval < lists.size()) {
      for (int i = 0; i < lists.size() - interval; i += (interval << 1)) {
        lists[i] = merge2Lists(lists, lists[i], lists[i + interval]);
      }
      interval <<= 1;
    }

    return lists.size() ? lists[0] : nullptr;
  }
};