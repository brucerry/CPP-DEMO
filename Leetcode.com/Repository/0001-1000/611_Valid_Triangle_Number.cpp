// https://leetcode.com/problems/valid-triangle-number/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(log(n)) for sorting

class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int result = 0, n = nums.size();
    for (int k = 2; k < n; k++) {
      for (int l = 0, r = k - 1; l < r; ) {
        if (nums[l] + nums[r] > nums[k]) {
          result += r - l;
          r--;
        }
        else
          l++;
      }
    }
    return result;
  }
};