// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/


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
  int pseudoPalindromicPaths (TreeNode* root) {
    int result = 0;
    solve(root, result, 0);
    return result;
  }
  
private:
  void solve(TreeNode* node, int& result, int mask) {
    if (!node)
      return;
    
    mask ^= 1 << node->val;
    
    if (!node->left and !node->right) {
      if ((mask & (mask - 1)) == 0)
        result++;
      return;
    }
    
    solve(node->left, result, mask);
    solve(node->right, result, mask);
  }
};