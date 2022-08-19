// https://leetcode.com/problems/increasing-order-search-tree/


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
  TreeNode* increasingBST(TreeNode* root) {
    return solve(root, nullptr);
  }
  
private:
  TreeNode* solve(TreeNode* node, TreeNode* tail) {
    if (!node)
      return tail;
    
    TreeNode* leftHead = solve(node->left, node);
    node->left = nullptr;
    node->right = solve(node->right, tail);
    
    return leftHead;
  }
};