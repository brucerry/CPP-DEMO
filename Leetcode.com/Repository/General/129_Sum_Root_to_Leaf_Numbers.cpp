// https://leetcode.com/problems/sum-root-to-leaf-numbers/


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
  int sumNumbers(TreeNode* root) {
    int sum = 0;
    solve(root, 0, sum);
    return sum;
  }
  
private:
  void solve(TreeNode* node, int cur, int& sum) {
    if (!node)
      return;
    
    cur = cur * 10 + node->val;
    
    if (!node->left and !node->right)
      sum += cur;
    
    solve(node->left, cur, sum);
    solve(node->right, cur, sum);
  }
};