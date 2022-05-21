// https://leetcode.com/problems/count-good-nodes-in-binary-tree/


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
  int goodNodes(TreeNode* root) {
    return solve(root, INT_MIN);
  }
  
private:
  int solve(TreeNode* node, int curMax) {
    if (!node)
      return 0;
    
    int good = 0;
    if (curMax <= node->val) {
      curMax = node->val;
      good = 1;
    }
    
    return good + solve(node->left, curMax) + solve(node->right, curMax);
  }
};