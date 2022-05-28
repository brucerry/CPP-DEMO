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
  // height, balance
  pair<int, bool> solve(TreeNode* node) {
    if (!node)
      return { 0, true };
    
    auto [ leftHeight, leftBalance ] = solve(node->left);
    if (!leftBalance)
      return { 0, false };
    
    auto [ rightHeight, rightBalance ] = solve(node->right);
    if (!rightBalance)
      return { 0, false };
    
    int height = 1 + max(leftHeight, rightHeight);
    bool balance = abs(leftHeight - rightHeight) <= 1;
    
    return { height, balance };
  }
};