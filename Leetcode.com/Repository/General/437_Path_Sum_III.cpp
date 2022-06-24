// https://leetcode.com/problems/path-sum-iii/

#include <unordered_map>
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
  int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long, int> prefixCount { // prefixSum, count
      { 0, 1 }
    };
    
    int result = 0;
    solve(root, targetSum, 0, result, prefixCount);
    return result;
  }
  
private:
  void solve(TreeNode* node, int targetSum, long curSum, int& result, unordered_map<long, int>& prefixCount) {
    if (!node)
      return;
    
    curSum += node->val;
    
    if (prefixCount.count(curSum - targetSum))
      result += prefixCount[curSum - targetSum];
    
    prefixCount[curSum]++;
    solve(node->left, targetSum, curSum, result, prefixCount);
    solve(node->right, targetSum, curSum, result, prefixCount);
    prefixCount[curSum]--;
  }
};