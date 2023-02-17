// https://leetcode.com/problems/minimum-distance-between-bst-nodes/


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
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, prev = -1;
        solve(root, res, prev);
        return res;
    }

private:
    void solve(TreeNode* node, int& res, int& prev) {
        if (node) {
            solve(node->left, res, prev);
            if (prev != -1)
                res = min(res, node->val - prev);
            prev = node->val;
            solve(node->right, res, prev);
        }
    }
};