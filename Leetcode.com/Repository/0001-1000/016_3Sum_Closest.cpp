// https://leetcode.com/problems/3sum-closest/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(log(n)) for sorting

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int result = 0, minDiff = INT_MAX, n = nums.size();
    for (int i = 0; i < n; i++) {
      int l = i + 1, r = n - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        int diff = abs(sum - target);
        if (diff < minDiff) {
          minDiff = diff;
          result = sum;
        }
        if (sum < target)
          l++;
        else
          r--;
      }
    }
    return result;
  }
};