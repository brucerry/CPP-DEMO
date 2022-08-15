// https://leetcode.com/problems/print-binary-tree/

#include <vector>
#include <string>
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
  vector<vector<string>> printTree(TreeNode* root) {
    int height = getHeight(root), rows = height + 1, cols = (1 << (height + 1)) - 1;
    vector<vector<string>> result (rows, vector<string>(cols));
    
    solve(result, root, 0, 0, cols - 1);
    return result;
  }
  
private:
  void solve(vector<vector<string>>& result, TreeNode* node, int r, int left, int right) {
    if (!node)
      return;
    
    int mid = left + (right - left) / 2;
    result[r][mid] = to_string(node->val);
    solve(result, node->left, r + 1, left, mid - 1);
    solve(result, node->right, r + 1, mid + 1, right);
  }
  
  int getHeight(TreeNode* root) {
    if (!root)
      return -1;
    return 1 + max(getHeight(root->left), getHeight(root->right));
  }
};