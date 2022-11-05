// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/

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

// n = # of nodes
// q = size of queries
// time: O(n + q)
// space: O(n)

class Solution {
public:
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    int heights[100001] {}, depths[100001] {}, h1[100001] {}, h2[100001] {};
    traverse(root, heights, depths, h1, h2, 0);
    
    vector<int> result;
    for (const int& node : queries) {
      int d = depths[node];
      int h = heights[node] == h1[d] ? h2[d] : h1[d];
      result.emplace_back(d + h - 1);
    }
    return result;
  }

private:
  int traverse(TreeNode* node, int* heights, int* depths, int* h1, int* h2, int d) {
    if (!node)
      return 0;

    int lh = traverse(node->left, heights, depths, h1, h2, d + 1);
    int rh = traverse(node->right, heights, depths, h1, h2, d + 1);
    int h = 1 + max(lh, rh);

    heights[node->val] = h;
    depths[node->val] = d;
    
    if (h > h1[d]) {
      h2[d] = h1[d];
      h1[d] = h;
    }
    else if (h > h2[d])
      h2[d] = h;

    return h;
  }
};