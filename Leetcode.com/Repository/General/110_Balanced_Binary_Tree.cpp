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
private:
  struct SubTreeState {
    bool isBalanced;
    int height;
  };

  SubTreeState helper(TreeNode* root) {
    if (!root)
      return { true, 0 };

    SubTreeState leftState = helper(root->left);
    
    if (!leftState.isBalanced)
      return { false, 0 };
    
    SubTreeState rightState = helper(root->right);
    
    if (!rightState.isBalanced)
      return { false, 0 };

    int height = 1 + max(leftState.height, rightState.height);
    bool isBalanced = abs(leftState.height - rightState.height) < 2;

    return { isBalanced, height };
  }
  
public:
  bool isBalanced(TreeNode* root) {
    return helper(root).isBalanced;
  }
};