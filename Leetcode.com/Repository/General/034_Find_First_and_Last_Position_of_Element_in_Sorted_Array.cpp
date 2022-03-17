// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int first = -1;
    int second = -1;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        if (mid == 0 || mid > 0 && nums[mid - 1] < nums[mid]) {
          first = mid;
          break;
        } else {
          right = mid - 1;
        }
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (first == -1) return {-1, -1};

    left = 0;
    right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        if (mid == nums.size() - 1 || mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
          second = mid;
          break;
        } else {
          left = mid + 1;
        }
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return {first, second};
  }
};