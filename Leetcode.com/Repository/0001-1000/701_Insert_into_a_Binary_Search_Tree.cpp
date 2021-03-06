// https://leetcode.com/problems/insert-into-a-binary-search-tree/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// time: O(height of tree)
// space: O(1)
class Iterative {
public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {    
    TreeNode* newNode = new TreeNode(val);
    
    if (!root)
      return newNode;
    
    TreeNode* prev = nullptr, *cur = root;
    while (cur) {
      prev = cur;
      if (val < cur->val)
        cur = cur->left;
      else
        cur = cur->right;
    }
    
    if (val < prev->val)
      prev->left = newNode;
    else
      prev->right = newNode;
    
    return root;
  }
};

// time: O(height of tree)
// space: O(height of tree)
class Recursive {
public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root)
      return new TreeNode(val);
    
    if (val < root->val)
      root->left = insertIntoBST(root->left, val);
    else
      root->right = insertIntoBST(root->right, val);
    
    return root;
  }
};