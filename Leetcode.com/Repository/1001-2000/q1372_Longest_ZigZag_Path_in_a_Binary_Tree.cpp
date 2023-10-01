// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

#include <array>
using namespace std;

// time: O(n)
// space: O(h)

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
    int longestZigZag(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }

private:
    array<int, 2> solve(TreeNode* cur, int& res) {
        if (!cur)
            return { -1, -1 };
        auto [ a, left_right ] = solve(cur->left, res);
        auto [ right_left, b ] = solve(cur->right, res);
        res = max(res, max(left_right, right_left) + 1);
        return { left_right + 1, right_left + 1 };
    }
};