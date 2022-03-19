// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int findMin(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    int ans = nums[0];

    while (l <= r) {
      if (nums[l] < nums[r]) {
        ans = min(ans, nums[l]);
        break;
      }

      int mid = l + ((r - l) >> 1);
      ans = min(ans, nums[mid]);

      if (nums[mid] > nums[r]) {
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }

    return ans;
  }
};