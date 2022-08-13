// https://leetcode.com/problems/find-mode-in-binary-search-tree/

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
  vector<int> findMode(TreeNode* root) {
    vector<int> modes;
    int maxFreq = 0, curVal = INT_MAX, curCount = 0;
    solve(root, modes, maxFreq, curVal, curCount);
    return modes;
  }
  
private:
  void solve(TreeNode* node, vector<int>& modes, int& maxFreq, int& curVal, int& curCount) {
    if (!node)
      return;
    
    solve(node->left, modes, maxFreq, curVal, curCount);
    
    if (node->val != curVal) {
      curVal = node->val;
      curCount = 0;
    }
    curCount++;
    if (curCount > maxFreq) {
      maxFreq = curCount;
      modes = { curVal };
    }
    else if (curCount == maxFreq) {
      modes.emplace_back(curVal);
    }
    
    solve(node->right, modes, maxFreq, curVal, curCount);
  }
};