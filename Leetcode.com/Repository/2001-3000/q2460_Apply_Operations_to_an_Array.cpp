// https://leetcode.com/problems/apply-operations-to-an-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> applyOperations(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      if (nums[i] == nums[i+1]) {
        nums[i] *= 2;
        nums[i+1] = 0;
      }
    }
    for (int l = 0, r = 0; r < n; r++) {
      if (nums[r])
        swap(nums[r], nums[l++]);
    }
    return nums;
  }
};