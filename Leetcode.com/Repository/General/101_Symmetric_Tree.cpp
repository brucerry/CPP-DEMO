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
  bool solve(TreeNode* n1, TreeNode* n2) {
    if (!n1 and !n2)
      return true;
    
    if (n1 and n2 and n1->val == n2->val)
      return solve(n1->left, n2->right) and solve(n1->right, n2->left);
    
    return false;
  }
};