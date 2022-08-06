// https://leetcode.com/problems/unique-binary-search-trees-ii/

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

class Solution {
public:
  vector<TreeNode*> generateTrees(int n) {
    return solve(1, n);
  }
  
private:
  vector<TreeNode*> solve(int start, int end) {
    if (start > end)
      return { nullptr };
    
    vector<TreeNode*> result;
    
    for (int rootval = start; rootval <= end; rootval++) {
      for (TreeNode* leftNode : solve(start, rootval - 1)) {
        for (TreeNode* rightNode : solve(rootval + 1, end)) {
          result.emplace_back(new TreeNode(rootval, leftNode, rightNode));
        }
      }
    }
    
    return result;
  }
};