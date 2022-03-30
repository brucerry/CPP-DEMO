// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result;
    result.reserve(nums.size());

    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int squared_l = nums[l] * nums[l];
      int squared_r = nums[r] * nums[r];
      if (squared_l > squared_r) {
        result.emplace_back(squared_l);
        l++;
      }
      else {
        result.emplace_back(squared_r);
        r--;
      }
    }

    reverse(result.begin(), result.end());

    return result;
  }
};