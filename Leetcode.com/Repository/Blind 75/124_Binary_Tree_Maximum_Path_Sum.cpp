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
    int sum = INT_MIN;
    solve(root, sum);
    return sum;
  }
  
private:
  int solve(TreeNode* node, int& sum) {
    if (!node)
      return 0;
    
    int leftSum = max(0, solve(node->left, sum));
    int rightSum = max(0, solve(node->right, sum));
    
    int split = node->val + leftSum + rightSum;
    int notSplit = node->val + max(leftSum, rightSum);
    sum = max(sum, split);
    
    return notSplit;
  }
};