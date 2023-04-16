// https://leetcode.com/problems/cousins-in-binary-tree-ii/

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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> que; // node, sum
        que.emplace(root, root->val);
        
        int levelsum = root->val;
        
        while (que.size()) {
            int curlevelsum = 0;
            for (int size = que.size(); size; size--) {
                auto [ node, sum ] = que.front();
                que.pop();
                node->val = levelsum - sum;
                int leftval = node->left ? node->left->val : 0;
                int rightval = node->right ? node->right->val : 0;
                int twosum = leftval + rightval;
                curlevelsum += twosum;
                if (node->left)
                    que.emplace(node->left, twosum);
                if (node->right)
                    que.emplace(node->right, twosum);
            }
            levelsum = curlevelsum;
        }
        
        return root;
    }
};