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

// time: O(n + k)
// space: O(n)

class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> stack;
    
    while (true) {
      while (root) {
        stack.emplace(root);
        root = root->left;
      }
      
      root = stack.top();
      stack.pop();
      
      if (--k == 0)
        return root->val;
      
      root = root->right;
    }
  }
};