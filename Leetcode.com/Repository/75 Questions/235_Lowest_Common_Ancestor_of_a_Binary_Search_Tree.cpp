// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// recursive
// time: O(height of tree)
// space: O(height of tree)
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {    
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};




// iterative
// time: O(height of tree)
// space: O(1)
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
      if (p->val < root->val && q->val < root->val) root = root->left;
      else if (p->val > root->val && q->val > root->val) root = root->right;
      else return root;
    }

    return nullptr;
  }
};