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
    if (!root)
      return root;
    
    convertBST(root->right);
    
    root->val += m_CurSum;
    m_CurSum = root->val;
    
    convertBST(root->left);
    
    return root;
  }
  
private:
  int m_CurSum = 0;
};

// time: O(n)
// space: O(n)
class Iterative {
public:
  TreeNode* convertBST(TreeNode* root) {
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
      
      cur->val += curSum;
      curSum = cur->val;
      
      cur = cur->left;
    }
    
    return root;
  }
};