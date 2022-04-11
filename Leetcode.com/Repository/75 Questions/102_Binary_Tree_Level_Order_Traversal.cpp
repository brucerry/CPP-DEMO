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
  void traverse(TreeNode* root, vector<vector<int>> &ans, int level) {
    if (!root)
      return;

    if (level < ans.size()) {
      ans[level].emplace_back(root->val);
    }
    else {
      ans.emplace_back(vector<int>(1, root->val));
    }

    traverse(root->left, ans, level + 1);
    traverse(root->right, ans, level + 1);
  }

public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    traverse(root, ans, 0);
    return ans;
  }

  // iterative BFS
  // vector<vector<int>> levelOrder(TreeNode* root) {
  //   vector<vector<int>> ans;
    
  //   queue<TreeNode*> queue;
  //   if (root)
  //     queue.emplace(root);
    
  //   while (queue.size()) {            
  //     vector<int> level;
  //     int size = queue.size();
  //     for (int i = 0; i < size; i++) {
  //       TreeNode* node = queue.front();
  //       queue.pop();
  //       if (node) {
  //         level.emplace_back(node->val);
  //         queue.emplace(node->left);
  //         queue.emplace(node->right);
  //       }
  //     }
  //     if (level.size())
  //       ans.emplace_back(level);
  //   }
    
  //   return ans;
  // }
};