// https://leetcode.com/problems/path-sum/


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
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root)
      return false;
    
    if (!root->left and !root->right and targetSum == root->val)
      return true;
    
    return hasPathSum(root->left, targetSum - root->val) or hasPathSum(root->right, targetSum - root->val);
  }
};