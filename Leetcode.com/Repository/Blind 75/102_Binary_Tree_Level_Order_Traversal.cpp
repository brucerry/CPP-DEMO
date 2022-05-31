// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <vector>
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
// space: O(height of tree)
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levels;
    solve(root, levels, 0);
    return levels;
  }
  
private:
  void solve(TreeNode* node, vector<vector<int>>& levels, int level) {
    if (!node)
      return;
    
    if (level == levels.size())
      levels.push_back({ node->val });
    else
      levels[level].emplace_back(node->val);
    
    solve(node->left, levels, level + 1);
    solve(node->right, levels, level + 1);
  }
};

// time: O(n)
// space: O(n)
class Iterative {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> queue;
    if (root)
      queue.emplace(root);
    
    vector<vector<int>> levels;
    while (queue.size()) {
      vector<int> level;
      int size = queue.size();
      
      while (size--) {
        TreeNode* node = queue.front();
        queue.pop();
        
        level.emplace_back(node->val);
        
        if (node->left)
          queue.emplace(node->left);
        if (node->right)
          queue.emplace(node->right);
      }
      
      if (level.size())
        levels.emplace_back(level);
    }
    
    return levels;
  }
};