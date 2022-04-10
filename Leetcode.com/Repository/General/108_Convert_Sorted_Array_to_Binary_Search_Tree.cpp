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
private:
  TreeNode* solve(vector<int>& nums, int left, int right) {
    if (left > right)
      return nullptr;
    
    int mid = left + ((right - left) >> 1);
    
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = solve(nums, left, mid - 1);
    root->right = solve(nums, mid + 1, right);
    
    return root;
  }
  
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return solve(nums, 0, nums.size() - 1);
  }
};