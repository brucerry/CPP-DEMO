// https://leetcode.com/problems/evaluate-boolean-binary-tree/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(n)
// space: O(height of tree)

class Solution {
public:
  bool evaluateTree(TreeNode* root) {
    if (root->val == 0 or root->val == 1)
      return root->val;
    
    bool leftval = evaluateTree(root->left);
    bool rightval = evaluateTree(root->right);
    
    return root->val == 2 ? leftval or rightval : leftval and rightval;
  }
};