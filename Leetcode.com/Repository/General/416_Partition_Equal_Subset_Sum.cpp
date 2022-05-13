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
    for (const int& num : nums)
      sum += num;
    
    if (sum & 1)
      return false;
    
    int half = sum >> 1;
    
    vector<char> dp (half + 1);
    dp[0] = 1;
    
    for (const int& num : nums) {
      for (int h = half; h >= 1; h--) {
        if (num <= h)
          dp[h] |= dp[h - num];
      }
    }
    
    return dp[half];
  }
};