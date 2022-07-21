// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <vector>
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
// space: O(1)
class MorrisTraversalWithoutTreeModification {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* cur = root;
    
    while (cur) {
      if (!cur->left) {
        ans.emplace_back(cur->val);
        cur = cur->right;
      }
      else {
        TreeNode* rightMostOfLeft = cur->left;
        while (rightMostOfLeft->right && rightMostOfLeft->right != cur) {
          rightMostOfLeft = rightMostOfLeft->right;
        }
        if (rightMostOfLeft->right == cur) {
          ans.emplace_back(cur->val);
          cur = cur->right;
          rightMostOfLeft->right = nullptr;
        }
        else {
          rightMostOfLeft->right = cur;
          cur = cur->left;
        }
      }
    }
    
    return ans;
  }
};

// time: O(n)
// space: O(1)
class MorrisTraversal {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    
    while (root) {
      if (!root->left) {
        ans.emplace_back(root->val);
        root = root->right;
      }
      else {
        TreeNode* rightMostOfLeft = root->left;
        while (rightMostOfLeft->right) {
          rightMostOfLeft = rightMostOfLeft->right;
        }
        rightMostOfLeft->right = root;
        TreeNode* tmp = root;
        root = root->left;
        tmp->left = nullptr;
      }
    }
    
    return ans;
  }
};

// time: O(n)
// space: O(n)
class Iterative {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    
    stack<TreeNode*> stack;
    while (root or stack.size()) {
      while (root) {
        stack.emplace(root);
        root = root->left;
      }
      
      root = stack.top();
      stack.pop();
      
      inorder.emplace_back(root->val);
      root = root->right;
    }
    
    return inorder;
  }
};

// time: O(n)
// space: O(height of tree)
class Recursive {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    solve(root, inorder);
    return inorder;
  }
  
private:
  void solve(TreeNode* node, vector<int>& inorder) {
    if (!node)
      return;
    
    solve(node->left, inorder);
    inorder.emplace_back(node->val);
    solve(node->right, inorder);
  }
};