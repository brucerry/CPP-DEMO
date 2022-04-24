// https://leetcode.com/problems/delete-node-in-a-bst/



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(height of tree)
// space: O(height of tree)

class Solution {
private:
  TreeNode* rightMostNode(TreeNode* node) {
    while (node->right)
      node = node->right;
    return node;
  }

  TreeNode* helper(TreeNode* targetNode) {
    if (!targetNode->left)
      return targetNode->right;

    if (!targetNode->right)
      return targetNode->left;

    TreeNode* rightMost = rightMostNode(targetNode->left);
    TreeNode* rightNode = targetNode->right;
    rightMost->right = rightNode;
    
    return targetNode->left;
  }

public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
      return root;

    if (root->val == key)
      return helper(root);

    TreeNode* cur = root;

    while (cur) {
      if (key < cur->val) {
        if (cur->left and cur->left->val == key) {
          cur->left = helper(cur->left);
          return root;
        }
        else
          cur = cur->left;
      }
      else {
        if (cur->right and cur->right->val == key) {
          cur->right = helper(cur->right);
          return root;
        }
        else
          cur = cur->right;
      }
    }
    
    return root;
  }
};