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
  int maxPathSum(TreeNode* root, int* maxSum) {
    if (!root) return 0;
    
    int leftMax = max(0, maxPathSum(root->left, maxSum));
    int rightMax = max(0, maxPathSum(root->right, maxSum));
    
    int withoutSplit = root->val + max(leftMax, rightMax);
    int split = root->val + leftMax + rightMax;
    
    *maxSum = max(*maxSum, split);
    
    return withoutSplit;
  }
  
public:
  int maxPathSum(TreeNode* root) {
    int maxSum = root->val;
    maxPathSum(root, &maxSum);
    return maxSum;
  }
};