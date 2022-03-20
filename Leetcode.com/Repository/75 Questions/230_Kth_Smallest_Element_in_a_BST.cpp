// https://leetcode.com/problems/kth-smallest-element-in-a-bst/


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
// space: O(n)

class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stack;
    TreeNode* cur = root;
    int count = 0;

    while (cur || stack.size()) {
      while (cur) {
        stack.push(cur);
        cur = cur->left;
      }

      cur = stack.top();
      stack.pop();

      if (++count == k) {
        return cur->val;
      }

      cur = cur->right;
    }

    return -1;
  }
};