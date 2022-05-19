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
    auto [ rob, skip ] = solve(root);
    return max(rob, skip);
  }
  
private:
  pair<int, int> solve(TreeNode* node) {
    if (!node)
      return { 0, 0 };
    
    auto [ leftrob, leftskip ] = solve(node->left);
    auto [ rightrob, rightskip ] = solve(node->right);
    
    int rob = node->val + leftskip + rightskip;
    int skip = max(leftrob, leftskip) + max(rightrob, rightskip);
    
    return { rob, skip };
  }
};