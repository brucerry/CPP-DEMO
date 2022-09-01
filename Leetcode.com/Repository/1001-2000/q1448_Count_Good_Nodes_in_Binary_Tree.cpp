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

class PassByReference {
public:
  int goodNodes(TreeNode* root) {
    int good = 0;
    solve(root, good, INT_MIN);
    return good;
  }
  
private:
  void solve(TreeNode* node, int& good, int pathMax) {
    if (!node)
      return;
    
    if (node->val >= pathMax) {
      good++;
      pathMax = node->val;
    }
    
    solve(node->left, good, pathMax);
    solve(node->right, good, pathMax);
  }
};

class OverloadingFunction {
public:
  int goodNodes(TreeNode* root, int pathMax = INT_MIN) {
    if (!root)
      return 0;
    
    int good = root->val >= pathMax;
    pathMax = max(pathMax, root->val);
    
    return good + goodNodes(root->left, pathMax) + goodNodes(root->right, pathMax);
  }
};