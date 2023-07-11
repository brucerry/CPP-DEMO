// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, int> dist; // val, dist from target along the root
        search(root, target, dist);
        vector<int> res;
        dfs(root, k, dist[root], dist, res);
        return res;
    }

private:
    int search(TreeNode* node, TreeNode* target, unordered_map<TreeNode*, int>& dist) {
        if (!node)
            return -1;
        
        if (node == target)
            return dist[node] = 0;

        int left = search(node->left, target, dist);
        if (left >= 0)
            return dist[node] = left + 1;

        int right = search(node->right, target, dist);
        if (right >= 0)
            return dist[node] = right + 1;

        return -1;
    }

    void dfs(TreeNode* node, int k, int len, unordered_map<TreeNode*, int>& dist, vector<int>& res) {
        if (!node)
            return;
        
        if (dist.count(node))
            len = dist[node];

        if (len == k)
            res.emplace_back(node->val);

        dfs(node->left, k, len + 1, dist, res);
        dfs(node->right, k, len + 1, dist, res);
    }
};