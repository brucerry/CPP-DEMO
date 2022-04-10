// https://leetcode.com/problems/diameter-of-binary-tree/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  int m_MaxDiameter = 0;
  
  int maxHeight(TreeNode* root) {
    if (!root)
      return -1;
    
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    
    m_MaxDiameter = max(m_MaxDiameter, leftHeight + rightHeight + 2);
    
    return 1 + max(leftHeight, rightHeight);
  }
  
public:
  int diameterOfBinaryTree(TreeNode* root) {
    maxHeight(root);
    return m_MaxDiameter;
  }
};