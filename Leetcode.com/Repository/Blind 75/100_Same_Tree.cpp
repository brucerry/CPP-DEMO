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

// time: O(n)
// space: O(n)
class Iterative {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<TreeNode*> nodes;
    nodes.emplace_back(p);
    nodes.emplace_back(q);
    
    while (nodes.size()) {
      TreeNode* n1 = nodes.back();
      nodes.pop_back();
      TreeNode* n2 = nodes.back();
      nodes.pop_back();
      
      if (!n1 and !n2)
        continue;
      else if (n1 and n2 and n1->val == n2->val) {
        nodes.emplace_back(n1->left);
        nodes.emplace_back(n2->left);
        nodes.emplace_back(n1->right);
        nodes.emplace_back(n2->right);
      }
      else
        return false;
    }
    
    return true;
  }
};

// time: O(n)
// space: O(height of tree)
class Recursive {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p and !q)
      return true;

    if (p and q and p->val == q->val)
      return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);

    return false;
  }
};