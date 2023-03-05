// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

#include <vector>
#include <queue>
#include <algorithm>
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> queue;
        queue.emplace(root);
        
        vector<long> sums;
        
        while (queue.size()) {
            long levelsum = 0;
            for (int size = queue.size(); size; size--) {
                TreeNode* node = queue.front();
                queue.pop();
                levelsum += node->val;
                if (node->left)
                    queue.emplace(node->left);
                if (node->right)
                    queue.emplace(node->right);
            }
            sums.emplace_back(levelsum);
        }
        
        if (sums.size() < k)
            return -1;

        nth_element(sums.begin(), sums.begin() + k - 1, sums.end(), greater<>());
        return sums[k - 1];
    }
};