// https://leetcode.com/problems/continuous-subarray-sum/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> remainderIndex { // remainder, end index
      { 0, -1 }
    };
    
    int curSum = 0;
    for (int i = 0; i < nums.size(); i++) {
      curSum += nums[i];
      int remainder = curSum % k;
      
      if (remainderIndex.count(remainder) == 0)
        remainderIndex[remainder] = i;
      else if (i - remainderIndex[remainder] >= 2)
        return true;
    }
    
    return false;
  }
};