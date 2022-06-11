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
      return { new TreeNode(0) };
    
    if (memo.count(n))
      return memo[n];
    
    for (int leftCount = 1; leftCount < n; leftCount++) {
      int rightCount = n - leftCount - 1;
      for (const auto& leftNode : solve(leftCount, memo)) {
        for (const auto& rightNode : solve(rightCount, memo)) {
          memo[n].emplace_back(new TreeNode(0, leftNode, rightNode));
        }
      }
    }
    
    return memo[n];
  }
};