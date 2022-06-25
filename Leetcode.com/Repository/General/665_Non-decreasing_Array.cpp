// https://leetcode.com/problems/non-decreasing-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    bool changed = false;
    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] > nums[i+1]) {
        if (changed)
          return false;
        changed = true;
        if (i == 0 or nums[i-1] <= nums[i+1])
          nums[i] = nums[i+1];
        else
          nums[i+1] = nums[i];
      }
    }
    return true;
  }
};