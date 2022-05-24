// https://leetcode.com/problems/target-sum/

#include <vector>
using namespace std;

// time: O(n * sum)
// space: O(sum)

class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (const int& num : nums)
      sum += num;
    
    if (abs(target) > sum)
      return 0;
    
    vector<int> dp ((sum << 1) + 1); // range from -sum to sum
    
    // sum is the index of array half
    dp[sum - nums[0]]++;
    dp[sum + nums[0]]++;
    
    for (int i = 1; i < nums.size(); i++) {
      vector<int> cur ((sum << 1) + 1);
      
      for (int s = -sum; s <= sum; s++) {
        if (dp[sum + s]) {
          cur[sum + s - nums[i]] += dp[sum + s];
          cur[sum + s + nums[i]] += dp[sum + s];
        }
      }

      dp = cur;
    }
    
    return dp[sum + target];
  }
};