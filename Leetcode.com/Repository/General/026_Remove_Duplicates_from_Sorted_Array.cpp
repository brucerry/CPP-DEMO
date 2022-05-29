// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int l = 1;

    for (int r = 1; r < nums.size(); r++) {
      if (nums[r-1] != nums[r])
        nums[l++] = nums[r];
    }
    
    return l;
  }
};