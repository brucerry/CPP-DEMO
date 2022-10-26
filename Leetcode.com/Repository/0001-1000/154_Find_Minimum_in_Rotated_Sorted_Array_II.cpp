// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <vector>
using namespace std;

// time: worst case O(n), best case O(log(n))
// space: O(1)

class Solution {
public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] < nums[r])
        r = m;
      else if (nums[m] > nums[r])
        l = m + 1;
      else
        r--;
    }
    return nums[r];
  }
};