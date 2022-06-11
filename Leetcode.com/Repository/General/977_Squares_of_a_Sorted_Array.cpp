// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> result (n);
    int l = 0, r = n - 1, i = n - 1;
    while (i >= 0) {
      int sqr_l = nums[l] * nums[l];
      int sqr_r = nums[r] * nums[r];
      if (sqr_l > sqr_r) {
        result[i--] = sqr_l;
        l++;
      }
      else {
        result[i--] = sqr_r;
        r--;
      }
    }
    return result;
  }
};