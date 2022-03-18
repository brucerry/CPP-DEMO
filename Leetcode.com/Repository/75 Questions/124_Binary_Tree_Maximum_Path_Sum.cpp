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
  int traverse(TreeNode* root, int* maxSum) {
    if (!root) return 0;

    int maxLeft = max(traverse(root->left, maxSum), 0);
    int maxRight = max(traverse(root->right, maxSum), 0);

    int withSplit = root->val + maxLeft + maxRight;
    int withoutSplit = root->val + max(maxLeft, maxRight);

    *maxSum = max(*maxSum, withSplit);

    return withoutSplit;
  }

public:
  int maxPathSum(TreeNode* root) {
    int maxSum = root->val;
    traverse(root, &maxSum);
    return maxSum;
  }
};