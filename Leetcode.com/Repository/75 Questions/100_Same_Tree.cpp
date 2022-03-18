// https://leetcode.com/problems/same-tree/

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

// p = # of nodes of p
// q = # of nodes of q
// time: O(p + q)
// space: O(p + q) for iterative, O(height of tree) for recursive

class Solution {
public:
  // iterative
  bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<TreeNode*> buffer;
    buffer.emplace_back(p);
    buffer.emplace_back(q);

    while (buffer.size()) {
      TreeNode* node1 = buffer.back();
      buffer.pop_back();
      TreeNode* node2 = buffer.back();
      buffer.pop_back();

      if (!node1 && !node2) continue;
      if (node1 && !node2 || !node1 && node2 || node1->val != node2->val) return false;
      
      buffer.emplace_back(node1->left);
      buffer.emplace_back(node2->left);
      buffer.emplace_back(node1->right);
      buffer.emplace_back(node2->right);
    }

    return true;
  }

  // recursive
  // bool isSameTree(TreeNode* p, TreeNode* q) {
  //   if (!p && !q) return true;
  //   if (!p && q || p && !q || p->val != q->val) return false;

  //   return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  // }
};