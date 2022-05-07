// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// time: O(height of tree)
// space: O(height of tree)
class Recursive {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val and q->val < root->val)
      return lowestCommonAncestor(root->left, p, q);
    
    else if (root->val < p->val and root->val < q->val)
      return lowestCommonAncestor(root->right, p, q);
    
    return root;
  }
};



// time: O(height of tree)
// space: O(1)
class Iterative {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
      if (p->val < root->val and q->val < root->val)
        root = root->left;
      
      else if (p->val > root->val and q->val > root->val)
        root = root->right;
      
      else
        break;
    }
    return root;
  }
};