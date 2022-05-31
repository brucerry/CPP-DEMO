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
// k = # of lists
// time: O(n * log(k))
// space: O(1)
class Iterative {
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
};

// n = # of nodes in each list
// k = # of lists
// time: O(n * log(k))
// space: O(log(k))
class Recursive {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return solve(lists, 0, lists.size() - 1);
  }
  
private:
  ListNode* solve(vector<ListNode*>& lists, int l, int r) {
    if (l == r)
      return lists[l];
    
    ListNode dummy, *cur = &dummy;
    
    if (l < r) {
      int m = l + ((r - l) >> 1);
      ListNode* leftptr = solve(lists, l, m);
      ListNode* rightptr = solve(lists, m + 1, r);

      while (leftptr and rightptr) {
        if (leftptr->val < rightptr->val) {
          cur->next = leftptr;
          leftptr = leftptr->next;
        }
        else {
          cur->next = rightptr;
          rightptr = rightptr->next;
        }
        cur = cur->next;
      }

      if (leftptr)
        cur->next = leftptr;

      if (rightptr)
        cur->next = rightptr;
    }    
    
    return dummy.next;
  }
};