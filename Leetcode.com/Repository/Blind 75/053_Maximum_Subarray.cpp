// https://leetcode.com/problems/maximum-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int ans = nums[0];
    int curSum = 0;

    for (int& num : nums) {
      curSum = max(curSum + num, num);
      ans = max(ans, curSum);
    }

    return ans;
  }
};