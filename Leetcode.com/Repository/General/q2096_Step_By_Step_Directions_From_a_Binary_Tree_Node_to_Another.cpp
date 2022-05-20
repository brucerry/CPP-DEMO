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
    string path_src, path_dst;
    findPath(root, startValue, path_src);
    findPath(root, destValue, path_dst);
    
    reverse(path_src.begin(), path_src.end());
    reverse(path_dst.begin(), path_dst.end());
    
    int s = 0, t = 0;
    while (s < path_src.length() and t < path_dst.length() and path_src[s] == path_dst[t]) {
      s++;
      t++;
    }
    
    return string(path_src.length() - s, 'U') + path_dst.substr(t);
  }
  
private:
  bool findPath(TreeNode* node, int target, string& path) {
    if (!node)
      return false;
    
    if (node->val == target)
      return true;
    
    if (findPath(node->left, target, path)) {
      path += 'L';
      return true;
    }
    
    if (findPath(node->right, target, path)) {
      path += 'R';
      return true;
    }
    
    return false;
  }
};