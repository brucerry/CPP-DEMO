// https://leetcode.com/problems/count-complete-tree-nodes/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(log(n) * log(n))
// space: O(log(n))

class Solution {
public:
  int countNodes(TreeNode* root) {
    int height = getHeight(root);
    if (height == -1)
      return 0;
    return getHeight(root->right) == height - 1 ?
           (1 << height) + countNodes(root->right) :
           (1 << height - 1) + countNodes(root->left);
  }

private:
  int getHeight(TreeNode* node) {
    return !node ? -1 : 1 + getHeight(node->left);
  }
};