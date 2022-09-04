// https://leetcode.com/problems/longest-nice-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    int result = 0;
    for (int l = 0, r = 0, curMask = 0; r < nums.size(); r++) {
      while (curMask & nums[r]) {
        curMask ^= nums[l++];
      }
      curMask |= nums[r];
      result = max(result, r - l + 1);
    }
    return result;
  }
};