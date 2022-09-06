// https://leetcode.com/problems/binary-tree-pruning/


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

class Solution1 {
public:
  TreeNode* pruneTree(TreeNode* root) {
    prune(root);
    return root;
  }
  
private:
  bool prune(TreeNode*& node) {
    if (!node)
      return node;

    bool sub = node->val | prune(node->left) | prune(node->right);

    if (!sub)
      node = nullptr;

    return node;
  }
};

class Solution2 {
public:
  TreeNode* pruneTree(TreeNode*& root) {
    if (!root)
      return root;
    
    bool sub = root->val | (size_t)pruneTree(root->left) | (size_t)pruneTree(root->right);
    
    if (!sub) 
      root = nullptr;
    
    return root;
  }
};

class Solution3 {
public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root)
      return root;
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    
    if (!root->left and !root->right and !root->val)
      return nullptr;
    
    return root;
  }
};