// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    int longest = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (r and nums[r-1] >= nums[r])
        l = r;
      longest = max(longest, r - l + 1);
    }
    return longest;
  }
};