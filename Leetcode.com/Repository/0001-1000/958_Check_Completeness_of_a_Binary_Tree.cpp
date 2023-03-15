// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.emplace(root);

        bool end = false;
        while (queue.size()) {
            TreeNode* node = queue.front();
            queue.pop();
            end = end or !node;
            if (node){
                if (end)
                    return false;
                queue.emplace(node->left);
                queue.emplace(node->right);
            }
        }
        return true;
    }
};