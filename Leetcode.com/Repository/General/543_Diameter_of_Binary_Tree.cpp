// https://leetcode.com/problems/diameter-of-binary-tree/


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
  int diameterOfBinaryTree(TreeNode* root) {
    int maxDiameter = 0;
    maxHeight(root, maxDiameter);
    return maxDiameter;
  }

private:
  int maxHeight(TreeNode* node, int& maxDiameter) {
    if (!node)
      return -1;
    
    int leftHeight = maxHeight(node->left, maxDiameter);
    int rightHeight = maxHeight(node->right, maxDiameter);
    
    int height = 1 + max(leftHeight, rightHeight);
    int diameter = 2 + leftHeight + rightHeight;
    maxDiameter = max(maxDiameter, diameter);
    
    return height;
  }
};