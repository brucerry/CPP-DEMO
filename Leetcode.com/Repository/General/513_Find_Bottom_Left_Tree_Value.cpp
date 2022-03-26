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
    queue.push(root);

    int ans = root->val;

    while (queue.size()) {
      TreeNode* node = queue.front();
      queue.pop();

      ans = node->val;

      if (node->right) queue.push(node->right);
      if (node->left) queue.push(node->left);
    }

    return ans;
  }
};