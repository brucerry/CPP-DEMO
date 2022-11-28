// https://leetcode.com/problems/remove-nodes-from-linked-list/

#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// time: O(n)
// space: O(n)

class Solution {
public:
  ListNode* removeNodes(ListNode* head) {
    vector<ListNode*> stack;
    while (head) {
      while (stack.size() and head->val > stack.back()->val)
        stack.pop_back();
      stack.emplace_back(head);
      head = head->next;
    }
    
    ListNode* dummy = new ListNode(), *cur = dummy;
    for (auto node : stack) {
      cur->next = node;
      cur = cur->next;
    }
    
    return dummy->next;
  }
};