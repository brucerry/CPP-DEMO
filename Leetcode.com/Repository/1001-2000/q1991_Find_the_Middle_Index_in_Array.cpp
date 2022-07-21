// https://leetcode.com/problems/find-the-middle-index-in-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int findMiddleIndex(vector<int>& nums) {
    int sum = 0;
    for (const int& num : nums)
      sum += num;
    
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int rightSum = sum - leftSum - nums[i];
      if (leftSum == rightSum)
        return i;
      leftSum += nums[i];
    }
    
    return -1;
  }
};