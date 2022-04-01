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
  bool isValidBST(long leftVal, TreeNode* root, long rightVal) {
    if (!root) return true;
    
    if (leftVal < root->val && root->val < rightVal) {
      return isValidBST(leftVal, root->left, root->val) && isValidBST(root->val, root->right, rightVal);
    }
    
    return false;
  }
  
public:
  bool isValidBST(TreeNode* root) {
    return isValidBST(LONG_MIN, root, LONG_MAX);
  }
};