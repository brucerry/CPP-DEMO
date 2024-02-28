// https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.emplace(root);
        while (que.size()) {
            TreeNode* cur = que.front();
            que.pop();
            root = cur;
            if (cur->right)
                que.emplace(cur->right);
            if (cur->left)
                que.emplace(cur->left);
        }
        return root->val;
    }
};