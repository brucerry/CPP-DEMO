// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <vector>
using namespace std;

// time: worst case O(n), best case O(log(n))
// space: O(1)

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    
    while (l <= r) {
      while (l < r && nums[l] == nums[l + 1])
        l++;
      while (l < r && nums[r] == nums[r - 1])
        r--;

      int m = l + ((r - l) >> 1);
      
      if (nums[m] == target)
        return true;
      
      else if (nums[l] <= nums[m]) {
        if (nums[m] < target or target < nums[l])
          l = m + 1;
        else
          r = m - 1;
      }
      
      else {
        if (nums[m] > target or target > nums[r])
          r = m - 1;
        else
          l = m + 1;
      }
    }
    
    return false;
  }
};