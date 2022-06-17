// https://leetcode.com/problems/binary-tree-cameras/


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
  int minCameraCover(TreeNode* root) {
    int camera = 0;
    if (solve(root, camera) == NEED)
      camera++;
    return camera;
  }
  
private:
  enum {
    NEED,
    NOT_NEED,
    HAS_CAMERA
  };
  
  int solve(TreeNode* node, int& camera) {
    if (!node)
      return NOT_NEED;
    
    int leftState = solve(node->left, camera);
    int rightState = solve(node->right, camera);
    
    if (leftState == NEED or rightState == NEED) {
      camera++;
      return HAS_CAMERA;
    }
    
    return leftState == HAS_CAMERA or rightState == HAS_CAMERA ? NOT_NEED : NEED;
  }
};