// https://leetcode.com/problems/flip-equivalent-binary-trees/


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// n1 = # of nodes of root1
// n2 = # of nodes of root2
// h1 = height of root1
// h2 = height of root2
// time: O(min(n1, n2))
// space: O(min(h1, h2))

class Solution {
public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (!root1 and !root2)
      return true;
    
    if (root1 and root2 and root1->val == root2->val) {
      bool notFlipCheck = flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
      bool flipCheck = flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left);
      return notFlipCheck or flipCheck;
    }
    
    return false;
  }
};