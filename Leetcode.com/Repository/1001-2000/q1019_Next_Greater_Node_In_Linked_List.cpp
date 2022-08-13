// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
  vector<int> nextLargerNodes(ListNode* head) {
    vector<int> result, stack;
    for (; head; head = head->next) {
      while (stack.size() and result[stack.back()] < head->val) {
        result[stack.back()] = head->val;
        stack.pop_back();
      }
      stack.emplace_back(result.size());
      result.emplace_back(head->val);
    }
    
    for (const int& i : stack)
      result[i] = 0;
    
    return result;
  }
};