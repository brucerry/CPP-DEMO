// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/


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
  int maxProduct(TreeNode* root) {
    long res = 0, totalsum = getSubsum(root, res);
    getSubsum(root, res, totalsum);
    return res % 1000000007;
  }

private:
  int getSubsum(TreeNode* node, long& res, long totalsum = 0) {
    if (!node)
      return 0;
    long subsum = node->val + getSubsum(node->left, res, totalsum) + getSubsum(node->right, res, totalsum);
    res = max(res, (totalsum - subsum) * subsum);
    return subsum;
  }
};