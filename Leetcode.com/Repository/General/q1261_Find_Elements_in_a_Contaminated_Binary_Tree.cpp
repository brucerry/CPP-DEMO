// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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

// time: O(n) for constructor, O(1) for find()
// space: O(n)

class FindElements {
public:
  FindElements(TreeNode* root) {
    traverse(root, 0);
  }
  
  bool find(int target) {
    return valueSet.count(target);
  }
  
private:
  unordered_set<int> valueSet;
  
  void traverse(TreeNode* node, int val) {
    if (!node)
      return;
    
    valueSet.insert(val);
    
    traverse(node->left, val * 2 + 1);
    traverse(node->right, val * 2 + 2);
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */