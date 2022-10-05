// https://leetcode.com/problems/add-one-row-to-tree/


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
  TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1) {
      return new TreeNode(val, root, nullptr);
    }

    solve(root, val, depth - 1);
    return root;
  }

private:
  void solve(TreeNode* node, int val, int depth) {
    if (!node)
      return;

    if (depth == 1) {
      TreeNode* newleft = new TreeNode(val, node->left, nullptr);
      TreeNode* newright = new TreeNode(val, nullptr, node->right);
      node->left = newleft;
      node->right = newright;
      return;
    }

    solve(node->left, val, depth - 1);
    solve(node->right, val, depth - 1);
  }
};