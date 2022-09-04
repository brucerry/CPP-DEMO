// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

#include <vector>
#include <map>
#include <set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// r = # of rows
// c = # of cols
// n = # of nodes
// time: O(n * log(r) * log(c) * log(n))
// space: O(n)

class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> colRowMultiset; // col, row, nums
    solve(root, colRowMultiset, 0, 0);
    
    vector<vector<int>> result;
    for (const auto& [ _, map ] : colRowMultiset) {
      result.push_back({});
      auto& back = result.back();
      for (const auto& [ _, mset ] : map) {
        back.insert(back.end(), mset.begin(), mset.end());
      }
    }
    return result;
  }
  
private:
  void solve(TreeNode* node, map<int, map<int, multiset<int>>>& colRowMultiset, int r, int c) {
    if (!node)
      return;
    
    colRowMultiset[c][r].emplace(node->val);
    
    solve(node->left, colRowMultiset, r + 1, c - 1);
    solve(node->right, colRowMultiset, r + 1, c + 1);
  }
};