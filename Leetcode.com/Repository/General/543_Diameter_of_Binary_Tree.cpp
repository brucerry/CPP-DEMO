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
    int ans = 0;
    maxHeight(root, ans);
    return ans;
  }

private:
  int maxHeight(TreeNode* node, int& ans) {
    if (!node)
      return -1;
    
    int leftHeight = maxHeight(node->left, ans);
    int rightHeight = maxHeight(node->right, ans);
    
    int height = 1 + max(leftHeight, rightHeight);
    int diameter = 2 + leftHeight + rightHeight;
    ans = max(ans, diameter);
    
    return height;
  }
};