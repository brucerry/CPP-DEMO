// https://leetcode.com/problems/balance-a-binary-search-tree/

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
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sorted;
        dfs(root, sorted);
        return solve(sorted, 0, sorted.size() - 1);
    }

private:
    void dfs(TreeNode* cur, vector<TreeNode*>& sorted) {
        if (cur) {
            dfs(cur->left, sorted);
            sorted.emplace_back(cur);
            dfs(cur->right, sorted);
        }
    }

    TreeNode* solve(vector<TreeNode*>& sorted, int l, int r) {
        if (l > r)
            return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* lnode = solve(sorted, l, m - 1);
        TreeNode* rnode = solve(sorted, m + 1, r);
        return new TreeNode(sorted[m]->val, lnode, rnode);
    }
};

// time: O(n * log(n))
// space: O(log(n))
class ManuallyBalance {
public:
    TreeNode* balanceBST(TreeNode* root) {
        TreeNode dummy (0, nullptr, root);
        solve(&dummy, dummy.right);
        return dummy.right;
    }
  
private:
    // return { height, balance }
    pair<int, int> solve(TreeNode* root, TreeNode* child) {
        if (!child)
            return { 0, 0 };

        auto [ leftHeight, leftBalance ] = solve(child, child->left);
        auto [ rightHeight, rightBalance ] = solve(child, child->right);

        int balance = leftHeight - rightHeight;

        if (balance > 1) {
            if (leftBalance < 0)
            rotateLeft(child, child->left);
            return solve(root, rotateRight(root, child));
        }

        if (balance < -1) {
            if (rightBalance > 0)
            rotateRight(child, child->right);
            return solve(root, rotateLeft(root, child));
        }

        int height = 1 + max(leftHeight, rightHeight);
        return { height, balance };
    }

    TreeNode* rotateLeft(TreeNode* node, TreeNode* child) {
        TreeNode* tmp = child->right;
        child->right = tmp->left;
        tmp->left = child;

        if (node->left == child)
            node->left = tmp;
        else
            node->right = tmp;

        return tmp;
    }

    TreeNode* rotateRight(TreeNode* node, TreeNode* child) {
        TreeNode* tmp = child->left;
        child->left = tmp->right;
        tmp->right = child;

        if (node->left == child)
            node->left = tmp;
        else
            node->right = tmp;

        return tmp;
    }
};