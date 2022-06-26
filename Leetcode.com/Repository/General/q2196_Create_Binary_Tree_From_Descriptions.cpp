// https://leetcode.com/problems/create-binary-tree-from-descriptions/

#include <vector>
#include <unordered_map>
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
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<int, pair<TreeNode*, bool>> valNodeInfo; // val, { node*, hasParent }
    
    for (const auto& des : descriptions) {
      int parent = des[0];
      int child = des[1];
      bool isLeft = des[2];
      
      if (valNodeInfo.count(parent) == 0)
        valNodeInfo[parent] = { new TreeNode(parent), false };
      
      if (valNodeInfo.count(child) == 0)
        valNodeInfo[child] = { new TreeNode(child), true };
      
      auto& [ parentNode, _ ] = valNodeInfo[parent];
      auto& [ childNode, hasParent ] = valNodeInfo[child];
      hasParent = true;
      
      if (isLeft)
        parentNode->left = childNode;
      else
        parentNode->right = childNode;
    }
    
    for (const auto& [ val, NodeInfo ] : valNodeInfo) {
      auto& [ node, hasParent] = NodeInfo;
      if (!hasParent)
        return node;
    }
    
    return nullptr;
  }
};