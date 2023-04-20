// https://leetcode.com/problems/maximum-width-of-binary-tree/

#include <queue>
using namespace std;

// time: O(n)
// space: O(n)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> que;
        que.emplace(root, 1);
        long res = 1;
        while (que.size()) {
            long startid = que.front().second;
            res = max(res, que.back().second - startid + 1);
            for (int size = que.size(); size; size--) {
                auto [ node, id ] = que.front();
                que.pop();
                id -= startid;
                if (node->left)
                    que.emplace(node->left, id * 2);
                if (node->right)
                    que.emplace(node->right, id * 2 + 1);
            }
        }
        return res;
    }
};