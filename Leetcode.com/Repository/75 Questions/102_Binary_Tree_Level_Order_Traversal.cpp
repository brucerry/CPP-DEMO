// https://leetcode.com/problems/binary-tree-level-order-traversal/


#include <vector>
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
private:
  void traverse(TreeNode* root, vector<vector<int>> &result, int level) {
    if (!root) return;

    if (level < result.size()) {
      result[level].push_back(root->val);
    }
    else {
      result.push_back({root->val});
    }

    traverse(root->left, result, level + 1);
    traverse(root->right, result, level + 1);
  }

public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    traverse(root, result, 0);
    return result;
  }

  // BFS
  // vector<vector<int>> levelOrder(TreeNode* root) {
  //   queue<TreeNode*> queue;
  //   if (root) queue.push(root);
    
  //   vector<vector<int>> result;
    
  //   while (queue.size()) {
  //     vector<int> level;
  //     const int size = queue.size();
  //     for (int i = 0; i < size; i++) {
  //       TreeNode* node = queue.front();
  //       queue.pop();
  //       if (node) {
  //         level.emplace_back(node->val);
  //         queue.push(node->left);
  //         queue.push(node->right);
  //       }
  //     }
  //     if (level.size()) result.emplace_back(level);
  //   }
    
  //   return result;
  // }
};