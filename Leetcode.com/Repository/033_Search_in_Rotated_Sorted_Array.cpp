// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target) return mid;

      // on the left sorted portion
      if (nums[left] <= nums[mid]) {
        if (target > nums[mid] || target < nums[left]) left = mid + 1;
        else right = mid - 1;
      }
      
      // on the right sorted portion
      else {
        if (target < nums[mid] || target > nums[right]) right = mid - 1;
        else left = mid + 1;
      }
    }

    return -1;
  }
};