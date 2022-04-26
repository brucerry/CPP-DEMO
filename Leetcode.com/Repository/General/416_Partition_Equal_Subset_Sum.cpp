// https://leetcode.com/problems/partition-equal-subset-sum/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n * sum/2)
// space: O(sum/2)

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (const int& num : nums) {
      sum += num;
    }
    
    if (sum & 1)
      return false;
    
    sum >>= 1;
    
    vector<char> dp (sum + 1);
    dp[0] = 1;
    
    for (const int& num : nums) {
      for (int s = sum; s >= 0; s--) {
        if (num > s)
          continue;
        
        dp[s] |= dp[s - num];
      }
    }
    
    return dp.back();
  }
};