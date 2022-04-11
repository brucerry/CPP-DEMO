// https://leetcode.com/problems/binary-tree-right-side-view/

#include <vector>
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

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> queue;
    if (root)
      queue.emplace(root);
    
    vector<int> ans;
    
    while (queue.size()) {
      const int size = queue.size();
      TreeNode* rightSideNode = nullptr;
      
      for (int i = 0; i < size; i++) {
        TreeNode* node = queue.front();
        queue.pop();
        
        if (i == size - 1)
          rightSideNode = node;
        
        if (node->left)
          queue.emplace(node->left);
        
        if (node->right)
          queue.emplace(node->right);
      }
      
      ans.emplace_back(rightSideNode->val);
    }
    
    return ans;
  }
};