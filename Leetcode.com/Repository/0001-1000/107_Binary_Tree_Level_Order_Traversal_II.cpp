// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
// space: O(n)

class Solution {
public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    queue<TreeNode*> queue;
    if (root)
      queue.emplace(root);
    
    vector<vector<int>> result;
    while (queue.size()) {
      int size = queue.size();
      vector<int> level;
      
      while (size--) {
        TreeNode* node = queue.front();
        queue.pop();
        
        level.emplace_back(node->val);
        
        if (node->left)
          queue.emplace(node->left);
        if (node->right)
          queue.emplace(node->right);
      }
      
      result.emplace_back(level);
    }
    
    reverse(result.begin(), result.end());
    return result;
  }
};