// https://leetcode.com/problems/combination-sum-iv/

#include <vector>
using namespace std;

// n = len of nums
// t = target
// time: O(n * t)
// space: O(t)
class BottomUpDP {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp (target + 1);
    dp[0] = 1;
    
    for (int t = 1; t <= target; t++) {
      for (const int& num : nums) {
        if (t >= num)
          dp[t] += dp[t - num];
      }
    }
    
    return dp[target];
  }
};

// n = len of nums
// t = target
// time: O(n * t)
// space: O(t)
class TopDownMemo {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<int> memo (target + 1, -1);
    return solve(nums, target, memo);
  }
  
private:
  int solve(vector<int>& nums, int target, vector<int>& memo) {
    if (target == 0)
      return 1;
    
    if (memo[target] != -1) {
      return memo[target];
    }
    
    int count = 0;
    
    for (int i = 0; i < nums.size(); i++) {
      if (target >= nums[i]) {
        count += solve(nums, target - nums[i], memo);
      }
    }
    
    return memo[target] = count;
  }
};