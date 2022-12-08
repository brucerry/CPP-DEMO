// https://leetcode.com/problems/leaf-similar-trees/

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

// m = # of nodes of root1
// n = # of nodes of root2
// time: O(m + n)
// space: O(m + n)

class Solution {
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> vec1, vec2;
    traverse(root1, vec1);
    traverse(root2, vec2);
    return vec1 == vec2;
  }

private:
  void traverse(TreeNode* node, vector<int>& vec) {
    if (!node)
      return;
    if (!node->left and !node->right)
      vec.emplace_back(node->val);
    traverse(node->left, vec);
    traverse(node->right, vec);
  }
};