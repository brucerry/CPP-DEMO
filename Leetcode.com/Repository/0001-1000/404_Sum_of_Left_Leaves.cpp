// https://leetcode.com/problems/sum-of-left-leaves/


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
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root)
      return 0;
    
    int sum = 0;
    if (root->left and !root->left->left and !root->left->right)
      sum = root->left->val;
    
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
  }
};