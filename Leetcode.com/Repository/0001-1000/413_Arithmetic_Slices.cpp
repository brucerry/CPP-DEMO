// https://leetcode.com/problems/arithmetic-slices/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int count = 0;
    for (int l = 1, r = 2; r < nums.size(); r++) {
      if (nums[l] - nums[l-1] != nums[r] - nums[r-1])
        l = r;
      count += r - l;
    }
    return count;
  }
};