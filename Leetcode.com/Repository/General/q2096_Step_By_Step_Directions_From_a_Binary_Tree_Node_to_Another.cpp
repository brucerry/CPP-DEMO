// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

#include <string>
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

// time: O(n)
// space: O(height of tree)

class Solution {
public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string path_s, path_t;
    
    traverse(root, startValue, path_s);
    traverse(root, destValue, path_t);
    
    reverse(path_s.begin(), path_s.end());
    reverse(path_t.begin(), path_t.end());
    
    int s = 0, t = 0;
    while (s < path_s.length() and t < path_t.length() and path_s[s] == path_t[t]) {
      s++;
      t++;
    }
    
    return string(path_s.length() - s, 'U') + path_t.substr(t);
  }
  
private:
  bool traverse(TreeNode* node, int target, string& path) {
    if (!node)
      return false;
    
    if (node->val == target)
      return true;
    
    if (traverse(node->left, target, path)) {
      path += 'L';
      return true;
    }
    
    if (traverse(node->right, target, path)) {
      path += 'R';
      return true;
    }
    
    return false;
  }
};