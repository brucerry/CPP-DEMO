// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

#include <unordered_set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(n * height of tree)
// space: O(height of tree)
class bstSolution {
public:
  bool findTarget(TreeNode* root, int k) {
    return solve(root, root, k);
  }
  
private:
  bool solve(TreeNode* root, TreeNode* cur, int target) {
    if (!cur)
      return false;
    return search(root, cur, target - cur->val) or solve(root, cur->left, target) or solve(root, cur->right, target);
  }
  
  bool search(TreeNode* root, TreeNode* cur, int remain) {
    if (!root)
      return false;
    
    if (root != cur and root->val == remain)
      return true;
    
    if (root->val < remain)
      return search(root->right, cur, remain);
    
    return search(root->left, cur, remain);
  }
};

// time: O(n)
// space: O(n)
class HashSet {
public:
  bool findTarget(TreeNode* root, int k) {
    unordered_set<int> remains;
    return solve(root, k, remains);
  }
  
private:
  bool solve(TreeNode* node, int target, unordered_set<int>& remains) {
    if (!node)
      return false;
    
    if (remains.count(target - node->val))
      return true;
    
    remains.insert(node->val);
    return solve(node->left, target, remains) or solve(node->right, target, remains);
  }
};