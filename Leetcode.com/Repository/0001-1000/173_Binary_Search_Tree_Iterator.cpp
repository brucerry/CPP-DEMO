// https://leetcode.com/problems/binary-search-tree-iterator/

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

// time: O(n) in worst case, O(1) in average
// space: O(height of tree)

class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    while (root) {
      stack.emplace(root);
      root = root->left;
    }
  }
  
  int next() {
    TreeNode* cur = stack.top();
    stack.pop();
    
    int val = cur->val;
    
    cur = cur->right;
    while (cur) {
      stack.emplace(cur);
      cur = cur->left;
    }
    
    return val;
  }
  
  bool hasNext() {
    return stack.size();
  }
  
private:
  stack<TreeNode*> stack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */