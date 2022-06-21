// https://leetcode.com/problems/minimum-size-subarray-sum/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, len = INT_MAX, curSum = 0;
    for (int r = 0; r < nums.size(); r++) {
      curSum += nums[r];
      while (curSum >= target) {
        len = min(len, r - l + 1);
        curSum -= nums[l++];
      }
    }
    return len == INT_MAX ? 0 : len;
  }
};