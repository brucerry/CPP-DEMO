// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
  vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.emplace(root);
    double levelSum = 0;
    
    vector<double> result;
    while (queue.size()) {
      int size = queue.size();
      levelSum = 0;
      
      for (int i = 0; i < size; i++) {
        TreeNode* node = queue.front();
        queue.pop();
        
        levelSum += node->val;
        
        if (node->left)
          queue.emplace(node->left);
        if (node->right)
          queue.emplace(node->right);
      }
      
      result.emplace_back(levelSum / size);
    }
    
    return result;
  }
};