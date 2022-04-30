// https://leetcode.com/problems/squares-of-a-sorted-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> squaredNums;
    
    int l = 0, r = nums.size() - 1;
    
    while (l <= r) {
      int squ_l = nums[l] * nums[l];
      int squ_r = nums[r] * nums[r];
      
      if (squ_l > squ_r) {
        squaredNums.emplace_back(squ_l);
        l++;
      }
      else {
        squaredNums.emplace_back(squ_r);
        r--;
      }
    }
    
    reverse(squaredNums.begin(), squaredNums.end());
    
    return squaredNums;
  }
};