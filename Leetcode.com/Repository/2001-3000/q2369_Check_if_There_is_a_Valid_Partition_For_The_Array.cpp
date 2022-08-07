// https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class SpaceOptimized {
public:
  bool validPartition(vector<int>& nums) {
    int n = nums.size();
    char one = 1, two = 1, three = 1;
    
    for (int i = n - 1; i >= 0; i--) {
      char tmp = 0;
      if (i + 1 < n and nums[i] == nums[i+1])
        tmp |= two;
      if (i + 2 < n and nums[i] == nums[i+1] and nums[i] == nums[i+2])
        tmp |= three;
      if (i + 2 < n and nums[i] == nums[i+1] - 1 and nums[i] == nums[i+2] - 2)
        tmp |= three;
      
      three = two;
      two = one;
      one = tmp;
    }
    
    return one;
  }
};

// time: O(n)
// space: O(n)
class DP {
public:
  bool validPartition(vector<int>& nums) {
    int n = nums.size();
    vector<char> dp (n + 1);
    dp.back() = 1;
    
    for (int i = n - 1; i >= 0; i--) {
      if (i + 1 < n and nums[i] == nums[i+1])
        dp[i] |= dp[i+2];
      if (i + 2 < n and nums[i] == nums[i+1] and nums[i] == nums[i+2])
        dp[i] |= dp[i+3];
      if (i + 2 < n and nums[i] == nums[i+1] - 1 and nums[i] == nums[i+2] - 2)
        dp[i] |= dp[i+3];
    }
    
    return dp[0];
  }
};