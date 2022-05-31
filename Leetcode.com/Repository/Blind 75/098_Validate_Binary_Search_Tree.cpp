// https://leetcode.com/problems/validate-binary-search-tree/

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
  bool isValidBST(TreeNode* root) {
    return solve(LONG_MIN, root, LONG_MAX);
  }
  
private:
  bool solve(long leftBound, TreeNode* node, long rightBound) {
    if (!node)
      return true;
    
    if (leftBound < node->val and node->val < rightBound)
      return solve(leftBound, node->left, node->val) and solve(node->val, node->right, rightBound);
    
    return false;
  }
};