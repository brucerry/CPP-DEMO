// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// time: O(n)
// space: O(height of tree)
class Recursive {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* lca;
    traverse(root, p, q, lca);
    return lca;
  }
  
private:
  bool traverse(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& lca) {
    if (!node)
      return false;
    
    bool leftFound = traverse(node->left, p, q, lca);
    bool rightFound = traverse(node->right, p, q, lca);
    bool midFound = node == p or node == q;
    
    if (leftFound + rightFound + midFound >= 2)
      lca = node;
    
    return leftFound or rightFound or midFound;
  }
};

// time: O(n)
// space: O(n)
class Iterative {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> stack;
    stack.emplace(root);
    
    unordered_map<TreeNode*, TreeNode*> parent {
      { root, nullptr }
    };
    
    while (parent.count(p) == 0 or parent.count(q) == 0) {
      TreeNode* node = stack.top();
      stack.pop();
      
      if (node->left) {
        parent[node->left] = node;
        stack.emplace(node->left);
      }
      
      if (node->right) {
        parent[node->right] = node;
        stack.emplace(node->right);
      }
    }
    
    unordered_set<TreeNode*> path_p;
    while (p) {
      path_p.emplace(p);
      p = parent[p];
    }
    
    while (path_p.count(q) == 0)
      q = parent[q];
    
    return q;
  }
};