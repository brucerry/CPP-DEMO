// https://leetcode.com/problems/count-good-nodes-in-binary-tree/


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
private:  
  int traverse(TreeNode* root, int prevMax) {
    if (!root)
      return 0;
    
    int count = 0;
    
    if (prevMax <= root->val) {
      count = 1;
      prevMax = root->val;
    }
    
    count += traverse(root->left, prevMax);
    count += traverse(root->right, prevMax);
    
    return count;
  }
  
public:
  int goodNodes(TreeNode* root) {
    return traverse(root, INT_MIN);
  }
};