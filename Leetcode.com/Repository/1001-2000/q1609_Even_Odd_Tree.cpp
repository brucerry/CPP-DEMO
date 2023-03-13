// https://leetcode.com/problems/even-odd-tree/

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.emplace(root);
        
        int level = 0;
        while (queue.size()) {
            int prev = level % 2 ? INT_MAX : -1;
            for (int size = queue.size(); size; size--) {
                TreeNode* node = queue.front();
                queue.pop();
                if (level % 2 == node->val % 2 or
                    level % 2 and prev <= node->val or
                    level % 2 == 0 and prev >= node->val)
                    return false;
                prev = node->val;
                if (node->left)
                    queue.emplace(node->left);
                if (node->right)
                    queue.emplace(node->right);
            }
            level++;
        }

        return true;
    }
};