// https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool canBeIncreasing(vector<int>& nums) {
    int remove = 0;
    for (int i = 1; i < nums.size() and remove < 2; i++) {
      if (nums[i-1] >= nums[i]) {
        remove++;
        if (i - 2 >= 0 and nums[i-2] >= nums[i])
          nums[i] = nums[i-1];
      }
    }
    return remove < 2;
  }
};