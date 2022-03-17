// https://leetcode.com/problems/maximum-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ans = nums[0];
    int partialSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      partialSum = max(partialSum + nums[i], nums[i]); // include or not to include
      ans = max(ans, partialSum);
    }

    return ans;
  }
};