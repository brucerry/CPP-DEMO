// https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (0 <= m - 1 and nums[m-1] == nums[m]) {
        if (m % 2)
          l = m + 1;
        else
          r = m - 1;
      }
      else if (m + 1 < n and nums[m] == nums[m+1]) {
        if (m % 2)
          r = m - 1;
        else
          l = m + 1;
      }
      else
        return nums[m];
    }
    return -1;
  }
};