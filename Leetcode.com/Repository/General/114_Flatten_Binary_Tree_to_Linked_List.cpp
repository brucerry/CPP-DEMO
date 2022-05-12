// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


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
  void flatten(TreeNode* root) {
    helper(root);
  }
  
private:
  TreeNode* helper(TreeNode* node) {
    if (!node)
      return nullptr;
    
    TreeNode* leftTail = helper(node->left);
    TreeNode* rightTail = helper(node->right);
    
    if (node->left) {
      leftTail->right = node->right;
      node->right = node->left;
      node->left = nullptr;
    }
    
    return rightTail ? rightTail : leftTail ? leftTail : node;
  }
};