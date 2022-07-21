// https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(up to the first leaf node)
// space: O(up to the first leaf node + rest of the nodes on the same level)
class BFS {
public:
  int minDepth(TreeNode* root) {
    queue<TreeNode*> queue;
    if (root)
      queue.emplace(root);
    
    int depth = 0;
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        TreeNode* node = queue.front();
        queue.pop();
        
        if (!node->left and !node->right)
          return depth + 1;
        
        if (node->left)
          queue.emplace(node->left);
        if (node->right)
          queue.emplace(node->right);
      }
      depth++;
    }
    
    return depth;
  }
};

// time: O(n)
// space: O(height of tree)
class DFS {
public:
  int minDepth(TreeNode* root) {
    if (!root)
      return 0;
    
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    return 1 + (leftDepth and rightDepth ? min(leftDepth, rightDepth) : max(leftDepth, rightDepth));
  }
};