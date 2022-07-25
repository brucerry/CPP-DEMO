// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int first = indexOf(nums, target, true);
    int last = indexOf(nums, target, false);
    return { first, last };
  }
  
private:
  int indexOf(vector<int>& nums, int target, bool leftBiased) {
    int index = -1, l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      if (nums[m] < target)
        l = m + 1;
      else if (nums[m] > target)
        r = m - 1;
      else {
        index = m;
        if (leftBiased)
          r = m - 1;
        else
          l = m + 1;
      }
    }
    return index;
  }
};