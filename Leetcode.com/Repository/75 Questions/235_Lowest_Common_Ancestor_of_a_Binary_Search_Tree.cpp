// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// time: O(log(n))
// space: O(1)

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur = root;

    while (cur) {
      if (p->val < cur->val && q->val < cur->val) cur = cur->left;
      else if (p->val > cur->val && q->val > cur->val) cur = cur->right;
      else return cur;
    }

    return nullptr;
  }
};