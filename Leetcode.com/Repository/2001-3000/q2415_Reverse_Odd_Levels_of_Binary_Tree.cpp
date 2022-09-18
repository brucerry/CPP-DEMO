// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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
  TreeNode* reverseOddLevels(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.emplace(root);
    
    vector<int> values;
    vector<TreeNode*> nodes;
    bool isOddLevel = false;
    
    while (queue.size()) {
      values = {};
      nodes = {};
      
      for (int size = queue.size(); size; size--) {
        TreeNode* node = queue.front();
        queue.pop();
        if (isOddLevel) {
          values.emplace_back(node->val);
          nodes.emplace_back(node);
        }
        if (node->left)
          queue.emplace(node->left);
        if (node->right)
          queue.emplace(node->right);
      }
      
      for (int n = nodes.size(), i = 0; i < n and isOddLevel; i++) {
        nodes[i]->val = values[n - 1 - i];
      }
      
      isOddLevel = !isOddLevel;
    }
    
    return root;
  }
};