// https://leetcode.com/problems/all-possible-full-binary-trees/

#include <vector>
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

// time: O(2^n)
// space: O(2^n)

class Solution {
public:
  vector<TreeNode*> allPossibleFBT(int n) {
    unordered_map<int, vector<TreeNode*>> memo;
    return solve(n, memo);
  }
  
private:
  vector<TreeNode*> solve(int n, unordered_map<int, vector<TreeNode*>>& memo) {
    if ((n & 1) == 0)
      return {};
    
    if (n == 1)
      return { new TreeNode() };
    
    if (memo.count(n))
      return memo[n];
    
    vector<TreeNode*> fbt;    
    for (int lCount = 0; lCount < n; lCount++) {
      int rCount = n - lCount - 1;
      
      vector<TreeNode*> leftChildren = solve(lCount, memo);
      vector<TreeNode*> rightChildren = solve(rCount, memo);
      
      for (const auto& lc : leftChildren) {
        for (const auto& rc : rightChildren) {
          fbt.emplace_back(new TreeNode(0, lc, rc));
        }
      }
    }
    
    return memo[n] = fbt;
  }
};