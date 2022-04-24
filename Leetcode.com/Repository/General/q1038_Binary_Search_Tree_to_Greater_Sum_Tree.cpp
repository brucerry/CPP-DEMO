// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

#include <stack>
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
// space: O(height of tree)
class Recursive {
public:
  TreeNode* bstToGst(TreeNode* root) {
    int curSum = 0;
    return helper(root, curSum);
  }
  
private:
  TreeNode* helper(TreeNode* node, int& curSum) {
    if (node) {
      helper(node->right, curSum);
      curSum = node->val = node->val + curSum;
      helper(node->left, curSum);
    }
    return node;
  }
};

// time: O(n)
// space: O(n)
class Iterative {
public:
  TreeNode* bstToGst(TreeNode* root) {
    stack<TreeNode*> stack;

    TreeNode* cur = root;

    int curSum = 0;

    while (stack.size() or cur) {
      while (cur) {
        stack.emplace(cur);
        cur = cur->right;
      }

      cur = stack.top();
      stack.pop();

      curSum = cur->val += curSum;

      cur = cur->left;
    }

    return root;
  }
};