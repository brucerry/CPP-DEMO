// https://leetcode.com/problems/find-duplicate-subtrees/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

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
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<long, pair<int, int>> orderCount; // traversal order, (count, id)
    vector<TreeNode*> result;
    solve(root, result, orderCount);
    return result;
  }
  
private:
  long solve(TreeNode* node, vector<TreeNode*>& result, unordered_map<long, pair<int, int>>& orderCount) {
    if (!node)
      return 0;
    
    long order = (unsigned long)node->val << 32 | solve(node->left, result, orderCount) << 16 | solve(node->right, result, orderCount);
    auto& [ count, id ] = orderCount[order];
    if (id == 0)
      id = orderCount.size();
    if (++count == 2)
      result.emplace_back(node);
    
    return id;
  }
};