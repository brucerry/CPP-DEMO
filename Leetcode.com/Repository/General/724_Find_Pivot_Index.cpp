// https://leetcode.com/problems/find-pivot-index/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for (const int& num : nums)
      sum += num;
    
    int leftSum = 0;
    
    for (int i = 0; i < nums.size(); i++) {
      if (leftSum == sum - leftSum - nums[i])
        return i;
      leftSum += nums[i];
    }
    
    return -1;
  }
};