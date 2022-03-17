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
private:
  pair<int, int> dfs(TreeNode* root) {
    if (root == nullptr) return {0, 0};

    pair<int, int> leftPair = dfs(root->left);
    pair<int, int> rightPair = dfs(root->right);

    int robThis = root->val + leftPair.second + rightPair.second;
    int skipThis = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);

    return {robThis, skipThis};
  }
public:
  int rob(TreeNode* root) {
    pair<int, int> result = dfs(root);
    return max(result.first, result.second);
  }
};