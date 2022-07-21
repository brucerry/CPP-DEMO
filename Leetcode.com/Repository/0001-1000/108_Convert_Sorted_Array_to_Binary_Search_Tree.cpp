// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
// space: O(log(n))

class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return solve(nums, 0, nums.size() - 1);
  }
  
private:
  TreeNode* solve(vector<int>& nums, int l, int r) {
    if (l > r)
      return nullptr;
    
    int m = l + ((r - l) >> 1);
    TreeNode* leftNode = solve(nums, l, m - 1);
    TreeNode* rightNode = solve(nums, m + 1, r);
    
    return new TreeNode(nums[m], leftNode, rightNode);
  }
};