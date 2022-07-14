// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <vector>
#include <algorithm>
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
// space: O(height of tree)
class TwoPointers {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int pre = 0, in = 0;
    return solve(preorder, inorder, pre, in, INT_MIN);
  }
  
private:
  TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& pre, int& in, int stop) {
    if (pre == preorder.size())
      return nullptr;
    
    if (inorder[in] == stop) {
      in++;
      return nullptr;
    }
    
    int rootVal = preorder[pre++];
    TreeNode* leftNode = solve(preorder, inorder, pre, in, rootVal);
    TreeNode* rightNode = solve(preorder, inorder, pre, in, stop);
    
    return new TreeNode(rootVal, leftNode, rightNode);
  }
};

// time: O(n)
// space: O(n)
class RuntimeOptimized {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    
    unordered_map<int, int> nodeIndex; // nodeVal, inorder index
    for (int i = 0; i < n; i++) {
      int val = inorder[i];
      nodeIndex[val] = i;
    }
    
    return solve(preorder, inorder, 0, n - 1, 0, n - 1, nodeIndex);
  }
  
private:
  TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int, int>& nodeIndex) {
    if (preStart > preEnd)
      return nullptr;
    
    int rootVal = preorder[preStart];
    int rootIndex = nodeIndex[rootVal];
    int leftSize = rootIndex - inStart;
    
    TreeNode* leftNode = solve(preorder, inorder, preStart + 1, preStart + leftSize, inStart, rootIndex - 1, nodeIndex);
    TreeNode* rightNode = solve(preorder, inorder, preStart + leftSize + 1, preEnd, rootIndex + 1, inEnd, nodeIndex);
    return new TreeNode(rootVal, leftNode, rightNode);
  }
};

// time: O(n^2)
// space: O(height of tree)
class SearchValueEveryTime {
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