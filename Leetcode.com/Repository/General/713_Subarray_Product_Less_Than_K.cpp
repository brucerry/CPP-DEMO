// https://leetcode.com/problems/subarray-product-less-than-k/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if (k <= 1)
      return 0;
    
    int curProduct = 1, subarray = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      curProduct *= nums[r];
      while (curProduct >= k) {
        curProduct /= nums[l++];
      }
      subarray += r - l + 1;
    }
    return subarray;
  }
};