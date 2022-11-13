// https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/

#include <vector>
#include <queue>
#include <numeric>
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

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int minimumOperations(TreeNode* root) {
    queue<TreeNode*> queue;
    queue.emplace(root);
    
    int res = 0;
    vector<int> level;
    while (queue.size()) {
      level = {};
      for (int size = queue.size(); size; size--) {
        TreeNode* node = queue.front();
        queue.pop();
        level.emplace_back(node->val);
        if (node->left)
          queue.emplace(node->left);
        if (node->right)
          queue.emplace(node->right);
      }
      res += minSwaps(level);
    }
    
    return res;
  }

private:

// i       0 1 2 3
// level = 7 6 8 5
// ids   = 2 1 3 0

  int minSwaps(vector<int>& level) {
    int n = level.size();
    vector<int> ids (n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int i, int j) {
      return level[i] < level[j];
    });
    int swaps = 0;
    for (int i = 0; i < n; i++) {
      for (; i != ids[i]; swaps++) {
        swap(ids[i], ids[ids[i]]);
      }
    }
    return swaps;
  }
};