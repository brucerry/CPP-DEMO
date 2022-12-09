// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(n)
// space: O(h)

class Solution {
public:
  int maxAncestorDiff(TreeNode* root) {
    return solve(root, root->val, root->val);
  }

private:
  int solve(TreeNode* node, int minval, int maxval) {
    if (!node)
      return maxval - minval;
    minval = min(minval, node->val);
    maxval = max(maxval, node->val);
    return max(solve(node->left, minval, maxval), solve(node->right, minval, maxval));
  }
};