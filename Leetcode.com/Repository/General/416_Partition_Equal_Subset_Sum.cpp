// https://leetcode.com/problems/partition-equal-subset-sum/

#include <vector>
using namespace std;

// time: O(n * sum/2)
// space: O(sum/2)

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (const int& num : nums)
      sum += num;
    
    if (sum & 1)
      return false;
    
    int target = sum >> 1;
    vector<char> dp (target + 1);
    dp[0] = 1;
    
    for (const int& num : nums) {
      for (int t = target; t >= 0; t--) {
        if (num <= t)
          dp[t] |= dp[t - num];
        
        if (dp[target])
          return true;
      }
    }
    
    return dp[target];
  }
};