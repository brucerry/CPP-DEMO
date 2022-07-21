// https://leetcode.com/problems/cousins-in-binary-tree/

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

// time: O(up to the level once we found x or y)
// space: O(up to the level once we found x or y + the rest number of nodes on that level)
class BFS {
public:
  bool isCousins(TreeNode* root, int x, int y) {
    queue<TreeNode*> queue;
    queue.emplace(root);
    
    while (queue.size()) {
      int size = queue.size();
      bool foundX = false, foundY = false;
      
      while (size--) {
        TreeNode* parent = queue.front();
        queue.pop();
        
        if (parent->val == x or parent->val == y)
          return false;
        
        TreeNode* leftChild = parent->left, *rightChild = parent->right;
        int leftVal = leftChild ? leftChild->val : 0;
        int rightVal = rightChild ? rightChild->val : 0;
        if ((leftVal == x and rightVal == y) or (leftVal == y and rightVal == x))
          return false;
        foundX = foundX or leftVal == x or rightVal == x;
        foundY = foundY or leftVal == y or rightVal == y;
        
        if (leftChild)
          queue.emplace(leftChild);
        if (rightChild)
          queue.emplace(rightChild);
      }
      
      if (foundX and foundY)
        return true;
      
      if ((foundX and !foundY) or (!foundX and foundY))
        return false;
    }
    
    return false;
  }
};

// time: O(n)
// space: O(height of tree)
class DFS {
public:
  bool isCousins(TreeNode* root, int x, int y) {
    auto [ x_parent, x_level ] = solve(root, x, 0, 0);
    auto [ y_parent, y_level ] = solve(root, y, 0, 0);
    
    return x_parent != y_parent and x_level == y_level;
  }
  
private:
  pair<int, int> solve(TreeNode* node, int target, int parent, int level) {
    if (!node)
      return { 0, 0 };
    
    if (node->val == target)
      return { parent, level };
    
    auto left = solve(node->left, target, node->val, level + 1);
    auto right = solve(node->right, target, node->val, level + 1);
    
    return left.first ? left : right;
  }
};