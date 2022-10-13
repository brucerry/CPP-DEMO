// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/


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
  int averageOfSubtree(TreeNode* root) {
    int result = 0;
    solve(root, result);
    return result;
  }
  
private:
  // curSum, number of nodes
  pair<int, int> solve(TreeNode* node, int& result) {
    if (!node)
      return { 0, 0 };
    
    auto [ leftsum, leftcount ] = solve(node->left, result);
    auto [ rightsum, rightcount ] = solve(node->right, result);
    int curSum = node->val + leftsum + rightsum;
    int count = leftcount + rightcount + 1;
    
    result += node->val == curSum / count;
    
    return { curSum, count };
  }
};