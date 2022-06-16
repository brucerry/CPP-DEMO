// https://leetcode.com/problems/most-frequent-subtree-sum/

#include <vector>
#include <unordered_map>
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
  vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> subsumCount; // subsum, count
    int maxcount = 0;
    collectSubsum(root, subsumCount, maxcount);
    
    vector<int> result;
    for (const auto& [ subsum, count ] : subsumCount) {
      if (count == maxcount)
        result.emplace_back(subsum);
    }
    
    return result;
  }
  
private:
  int collectSubsum(TreeNode* node, unordered_map<int, int>& subsumCount, int& maxcount) {
    if (!node)
      return 0;
    
    int leftsum = collectSubsum(node->left, subsumCount, maxcount);
    int rightsum = collectSubsum(node->right, subsumCount, maxcount);
    int subsum = node->val + leftsum + rightsum;
    
    subsumCount[subsum]++;
    maxcount = max(maxcount, subsumCount[subsum]);
    
    return subsum;
  }
};