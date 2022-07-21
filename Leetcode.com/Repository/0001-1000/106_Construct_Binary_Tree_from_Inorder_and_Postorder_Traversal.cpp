// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    int in = n - 1, post = n - 1;
    return solve(inorder, postorder, in, post, INT_MIN);
  }
  
private:
  TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& in, int& post, int stop) {
    if (post == -1)
      return nullptr;
    
    if (inorder[in] == stop) {
      in--;
      return nullptr;
    }
    
    int rootVal = postorder[post--];
    TreeNode* rightNode = solve(inorder, postorder, in, post, rootVal);
    TreeNode* leftNode = solve(inorder, postorder, in, post, stop);
    
    return new TreeNode(rootVal, leftNode, rightNode);
  }
};

// time: O(n)
// space: O(n)
class RuntimeOptimized {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    
    unordered_map<int, int> nodeIndex; // nodeVal, inorder index
    for (int i = 0; i < n; i++) {
      int val = inorder[i];
      nodeIndex[val] = i;
    }
    
    return solve(inorder, postorder, 0, n - 1, 0, n - 1, nodeIndex);
  }
  
private:
  TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& nodeIndex) {
    if (inStart > inEnd)
      return nullptr;
    
    int rootVal = postorder[postEnd];
    int rootIndex = nodeIndex[rootVal];
    int leftSize = rootIndex - inStart;
    
    TreeNode* leftNode = solve(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1, nodeIndex);
    TreeNode* rightNode = solve(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1, nodeIndex);
    
    return new TreeNode(rootVal, leftNode, rightNode);
  }
};

// time: O(n^2)
// space: O(height of tree)
class SearchValueEveryTime {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return solve(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
  }
  
private:
  TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd)
      return nullptr;
    
    int rootVal = postorder[postEnd];
    int rootIndex = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
    int leftSize = rootIndex - inStart;
    
    TreeNode* leftNode = solve(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    TreeNode* rightNode = solve(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
    
    return new TreeNode(rootVal, leftNode, rightNode);
  }
};