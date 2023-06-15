// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.emplace(root);
        
        int res = 1, max_sum = INT_MIN, level = 1;
        while (que.size()) {
            int sum = 0;
            for (int size = que.size(); size; size--) {
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                if (node->left)
                    que.emplace(node->left);
                if (node->right)
                    que.emplace(node->right);
            }
            if (sum > max_sum) {
                max_sum = sum;
                res = level;
            }
            level++;
        }

        return res;
    }
};