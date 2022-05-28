// https://leetcode.com/problems/symmetric-tree/


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
  bool isSymmetric(TreeNode* root) {
    return solve(root->left, root->right);
  }
  
private:
  bool solve(TreeNode* lNode, TreeNode* rNode) {
    if (!lNode and !rNode)
      return true;
    
    if (lNode and rNode and lNode->val == rNode->val)
      return solve(lNode->left, rNode->right) and solve(lNode->right, rNode->left);
    
    return false;
  }
};