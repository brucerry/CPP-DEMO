// https://leetcode.com/problems/validate-binary-search-tree/

#include <cstdlib>

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
private:
  bool isValidBST(long leftBound, TreeNode* root, long rightBound) {
    if (!root)
      return true;
    
    if (leftBound >= root->val || root->val >= rightBound)
      return false;
    
    return isValidBST(leftBound, root->left, root->val) && isValidBST(root->val, root->right, rightBound);
  }
  
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(LONG_MIN, root, LONG_MAX);
  }
};