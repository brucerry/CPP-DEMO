// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <iostream>
#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0;
    int sum = 0;
    int ans = INT_MAX;
    for (int r = 0; r < nums.size(); r++) {
      sum += nums[r];
      while (sum >= target) {
        ans = min(ans, r - l + 1);
        sum -= nums[l];
        l++;
      }
    }

    return ans == INT_MAX ? 0 : ans;
  }
};