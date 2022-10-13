// https://leetcode.com/problems/monotonic-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool isMonotonic(vector<int>& nums) {
    bool inc = true, dec = true;
    for (int i = 1; i < nums.size(); i++) {
      inc &= nums[i-1] <= nums[i];
      dec &= dec and nums[i-1] >= nums[i];
    }
    return inc or dec;
  }
};