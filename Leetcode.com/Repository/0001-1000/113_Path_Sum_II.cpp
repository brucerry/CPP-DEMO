// https://leetcode.com/problems/path-sum-ii/

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
public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> solution;
    vector<int> path;
    solve(root, targetSum, solution, path);
    return solution;
  }
  
private:
  void solve(TreeNode* node, int targetSum, vector<vector<int>>& solution, vector<int>& path) {
    if (!node)
      return;
    
    path.emplace_back(node->val);
    
    if (!node->left and !node->right and targetSum == node->val) {
      solution.emplace_back(path);
    }
    
    solve(node->left, targetSum - node->val, solution, path);
    solve(node->right, targetSum - node->val, solution, path);
    path.pop_back();
  }
};