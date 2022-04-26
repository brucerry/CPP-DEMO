// https://leetcode.com/problems/house-robber-iii/

#include <utility>
using namespace std;

// time: O(n)
// space: O(height of the tree)

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  int rob(TreeNode* root) {
    pair<int, int> ans = helper(root);
    return max(ans.first, ans.second);
  }
  
private:
  pair<int, int> helper(TreeNode* node) {
    if (!node)
      return { 0, 0 };
    
    auto [ leftRob, leftIgnore ] = helper(node->left);
    auto [ rightRob, rightIgnore ] = helper(node->right);
  
    int rob = node->val + leftIgnore + rightIgnore;
    int ignore = max(leftRob, leftIgnore) + max(rightRob, rightIgnore);
    
    return { rob, ignore };
  }
};