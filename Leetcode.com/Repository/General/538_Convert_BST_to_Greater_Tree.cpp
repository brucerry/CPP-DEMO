// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
  TreeNode* convertBST(TreeNode* root) {
    int curSum = 0;
    solve(root, curSum);
    return root;
  }
  
private:
  void solve(TreeNode* node, int& curSum) {
    if (!node)
      return;
    
    solve(node->right, curSum);
    curSum = node->val += curSum;
    solve(node->left, curSum);
  }
};

// time: O(n)
// space: O(n)
class Iterative {
public:
  TreeNode* convertBST(TreeNode* root) {
    stack<TreeNode*> stack;
    TreeNode* cur = root;
    int curSum = 0;
    
    while (cur or stack.size()) {
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