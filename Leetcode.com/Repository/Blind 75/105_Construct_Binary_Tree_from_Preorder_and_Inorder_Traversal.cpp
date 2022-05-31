// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <vector>
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return solve(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
  }
  
private:
  TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
    if (preStart > preEnd)
      return nullptr;
    
    int rootVal = preorder[preStart];
    int rootIndex = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
    int leftSize = rootIndex - inStart;
    
    TreeNode* leftNode = solve(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1);
    TreeNode* rightNode = solve(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd);
    
    return new TreeNode(rootVal, leftNode, rightNode);
  }
};