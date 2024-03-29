// https://leetcode.com/problems/find-peak-element/

#include <vector>
using namespace std;

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > nums[m+1])
        r = m;
      else
        l = m + 1;
    }
    return r;
  }
};