// https://leetcode.com/problems/linked-list-in-binary-tree/


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// n = # of tree nodes
// h = height of tree
// l = len of list
// time: O(n * min(l, h))
// space: O(h)

class Solution {
public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (!head)
      return true;

    if (!root)
      return false;

    return solve(head, root) or isSubPath(head, root->left) or isSubPath(head, root->right);
  }

private:
  bool solve(ListNode* head, TreeNode* root) {
    if (!head)
      return true;

    if (!root)
      return false;

    return head->val == root->val and (solve(head->next, root->left) or solve(head->next, root->right));
  }
};