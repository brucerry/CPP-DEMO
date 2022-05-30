// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      if (nums[m] == target)
        return m;
      
      // on the left sorted portion
      else if (nums[l] <= nums[m]) {
        if (nums[m] < target or target < nums[l])
          l = m + 1;
        else
          r = m - 1;
      }
      
      // on the right sorted portion
      else {
        if (nums[m] > target or target > nums[r])
          r = m - 1;
        else
          l = m + 1;
      }
    }
    
    return -1;
  }
};