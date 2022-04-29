// https://leetcode.com/problems/deepest-leaves-sum/

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
  int deepestLeavesSum(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.emplace(root);
    
    int sum = 0;
    
    while (queue.size()) {
      int size = queue.size();
      sum = 0;
      
      while (size--) {
        TreeNode* node = queue.front();
        queue.pop();
        
        sum += node->val;
        
        if (node->left)
          queue.emplace(node->left);
        
        if (node->right)
          queue.emplace(node->right);
      }
    }
    
    return sum;
  }
};