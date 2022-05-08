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
public:
  int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    helper(root, maxSum);
    return maxSum;
  }
  
private:
  int helper(TreeNode* node, int& maxSum) {
    if (!node)
      return 0;
    
    int leftSum = max(0, helper(node->left, maxSum));
    int rightSum = max(0, helper(node->right, maxSum));
    
    int split = node->val + leftSum + rightSum;
    int withoutSplit = node->val + max(leftSum, rightSum);
    
    maxSum = max(maxSum, split);
    
    return withoutSplit;
  }
};