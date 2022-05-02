// https://leetcode.com/problems/trim-a-binary-search-tree/


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
class Recursive {
public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root)
      return root;
    
    if (root->val < low)
      return trimBST(root->right, low, high);
    
    if (root->val > high)
      return trimBST(root->left, low, high);
    
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    
    return root;
  }
};

// time: O(n)
// space: O(1)
class Iterative {
public:
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    TreeNode dummy = TreeNode();
    dummy.left = root;
    
    TreeNode* prev = &dummy, *cur = root;
    
    while (cur) {
      if (cur->val < low) {
        prev->left = cur->right;
        cur = prev->left;
      }
      else {
        prev = cur;
        cur = cur->left;
      }
    }
    
    dummy.right = dummy.left;
    prev = &dummy;
    cur = dummy.right;
    
    while (cur) {
      if (cur->val > high) {
        prev->right = cur->left;
        cur = prev->right;
      }
      else {
        prev = cur;
        cur = cur->right;
      }
    }
    
    return dummy.right;
  }
};