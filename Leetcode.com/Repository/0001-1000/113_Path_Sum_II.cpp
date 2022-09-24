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
    vector<int> state;
    solve(root, targetSum, solution, state);
    return solution;
  }
  
private:
  void solve(TreeNode* node, int targetSum, vector<vector<int>>& solution, vector<int>& state) {
    if (!node)
      return;
    
    targetSum -= node->val;
    state.emplace_back(node->val);
    
    if (!node->left and !node->right and targetSum == 0) {
      solution.emplace_back(state);
    }
    
    solve(node->left, targetSum, solution, state);
    solve(node->right, targetSum, solution, state);
    
    state.pop_back();
  }
};