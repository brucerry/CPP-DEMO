// https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/

#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// n = # of nodes
// q = size of queries
// time: O(n + q * log(n))
// space: O(n)

class Solution {
public:
  vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
    vector<int> vals;
    dfs(root, vals);
    
    vector<vector<int>> res;
    for (const int& q : queries) {
      auto low = lower_bound(vals.begin(), vals.end(), q); // find the smallest val where q <= val
      auto up = upper_bound(vals.begin(), vals.end(), q); // find the smallest val where q < val
      int min = up == vals.begin() ? -1 : *(--up);
      int max = low == vals.end() ? -1 : *low;
      res.push_back({ min, max });
    }
    
    return res;
  }
  
private:
  void dfs(TreeNode* node, vector<int>& vals) {
    if (!node)
      return;
    dfs(node->left, vals);
    vals.emplace_back(node->val);
    dfs(node->right, vals);
  }
};