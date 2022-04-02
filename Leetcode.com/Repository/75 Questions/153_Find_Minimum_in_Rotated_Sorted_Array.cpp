// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    
    while (l < r) {
      int m = l + ((r - l) >> 1);
      
      if (nums[m] < nums[r]) r = m;
      else l = m + 1;
    }
    
    return nums[l];
  }
};