// https://leetcode.com/problems/binary-tree-maximum-path-sum/



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
  int m_MaxSum = INT_MIN;
  
  int solve(TreeNode* node) {
    if (!node)
      return 0;
    
    int leftSum = max(0, solve(node->left));
    int rightSum = max(0, solve(node->right));
    
    int split = node->val + leftSum + rightSum;
    int withoutSplit = node->val + max(leftSum, rightSum);
    
    m_MaxSum = max(m_MaxSum, split);
    
    return withoutSplit;
  }
  
public:
  int maxPathSum(TreeNode* root) {
    solve(root);
    return m_MaxSum;
  }
};