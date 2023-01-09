// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<TreeNode*> stack { root };
        while (stack.size()) {
            TreeNode* node = stack.back();
            stack.pop_back();
            if (node) {
                res.emplace_back(node->val);
                stack.emplace_back(node->right);
                stack.emplace_back(node->left);
            }
        }
        return res;
    }
};

class Recursive {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root, res);
        return res;
    }

private:
    void solve(TreeNode* node, vector<int>& res) {
        if (node) {
            res.emplace_back(node->val);
            solve(node->left, res);
            solve(node->right, res);
        }
    }
};