// https://leetcode.com/problems/construct-string-from-binary-tree/

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
  string tree2str(TreeNode* root) {
    if (!root)
      return "";
    
    string rootstr = to_string(root->val);
    string leftstr = tree2str(root->left);
    string rightstr = tree2str(root->right);
    
    if (leftstr == "" and rightstr == "")
      return rootstr;
    if (rightstr == "")
      return rootstr + '(' + leftstr + ')';
    if (leftstr == "")
      return rootstr + "()" + '(' + rightstr + ')';
    
    return rootstr + '(' + leftstr + ")(" + rightstr + ')';
  }
};