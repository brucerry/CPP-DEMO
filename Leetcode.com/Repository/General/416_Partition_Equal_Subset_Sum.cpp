// https://leetcode.com/problems/partition-equal-subset-sum/

#include <vector>
#include <numeric>
using namespace std;

// time: O(n * sum/2)
// space: O(sum/2)

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    if (sum & 1)
      return false;
    
    sum >>= 1;
    
    vector<char> dp (sum + 1, 0);
    dp[0] = 1;

    for (const int& num : nums) {
      for (int s = sum; s >= 0; s--) {
        if (num > s)
          continue;
        if (dp[s - num])
          dp[s] = 1;
        if (dp[sum])
          return true;
      }
    }
    
    return false;
  }
};