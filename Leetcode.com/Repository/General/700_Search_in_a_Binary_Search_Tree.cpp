// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
  TreeNode* searchBST(TreeNode* root, int val) {
    while (root) {
      if (val < root->val)
        root = root->left;
      else if (val > root->val)
        root = root->right;
      else
        break;
    }
    
    return root;
  }
};

// time: O(height of tree)
// space: O(height of tree)
class Recursive {
public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (!root or root->val == val)
      return root;
    
    if (val < root->val)
      return searchBST(root->left, val);
    
    return searchBST(root->right, val);
  }
};