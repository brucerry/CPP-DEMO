// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> queue;
    if (root)
      queue.emplace(root);
    
    bool fromLeft = true;
    vector<vector<int>> result;
    
    while (queue.size()) {
      int size = queue.size();
      vector<int> level (size);
      
      for (int i = 0; i < size; i++) {
        TreeNode* node = queue.front();
        queue.pop();
        
        int j = fromLeft ? i : size - 1 - i;
        level[j] = node->val;
        
        if (node->left)
          queue.emplace(node->left);
        if (node->right)
          queue.emplace(node->right);
      }
      
      fromLeft = !fromLeft;
      result.emplace_back(level);
    }
    
    return result;
  }
};