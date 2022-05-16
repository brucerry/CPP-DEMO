// https://leetcode.com/problems/maximum-subarray/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int largest = nums[0];
    int curSum = 0;
    
    for (const int& num : nums) {
      curSum = max(curSum + num, num);
      largest = max(largest, curSum);
    }
    
    return largest;
  }
};