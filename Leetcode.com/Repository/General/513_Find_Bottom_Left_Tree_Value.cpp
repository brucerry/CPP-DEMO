// https://leetcode.com/problems/find-bottom-left-tree-value/

#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(n)
// space: O(n)

class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.emplace(root);

    int val = root->val;
    while (queue.size()) {
      TreeNode* node = queue.front();
      queue.pop();

      val = node->val;

      if (node->right)
        queue.emplace(node->right);
      if (node->left)
        queue.emplace(node->left);
    }

    return val;
  }
};