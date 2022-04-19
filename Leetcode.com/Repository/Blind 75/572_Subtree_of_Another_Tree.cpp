// https://leetcode.com/problems/subtree-of-another-tree/



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// s = # of nodes of root tree
// t = # of nodes of subroot tree
// m = space complexity of isSameTree()
// time: O(s * t)
// space: O(height of root tree * m)

class Solution {
private:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q)
      return true;
    
    if (p && q && p->val == q->val)
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    
    return false;
  }
  
public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!subRoot)
      return true;
    
    if (!root)
      return false;
    
    if (isSameTree(root, subRoot))
      return true;
    
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};