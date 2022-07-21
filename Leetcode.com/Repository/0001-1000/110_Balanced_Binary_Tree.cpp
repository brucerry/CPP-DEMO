// https://leetcode.com/problems/balanced-binary-tree/

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
  bool isBalanced(TreeNode* root) {
    return solve(root).second;
  }
  
private:
  // height, isbalanced
  pair<int, bool> solve(TreeNode* node) {
    if (!node)
      return { 0, true };
    
    auto [ leftHeight, leftBalanced ] = solve(node->left);
    if (!leftBalanced)
      return { 0, false };
    
    auto [ rightHeight, rightBalanced ] = solve(node->right);
    if (!rightBalanced)
      return { 0, false };
    
    int height = 1 + max(leftHeight, rightHeight);
    bool isbalanced = abs(leftHeight - rightHeight) < 2;
    return { height, isbalanced };
  }
};