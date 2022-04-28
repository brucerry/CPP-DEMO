// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <vector>
using namespace std;

// time: O(2^(n*k))
// space: O(n*k)

class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    
    for (const int& num : nums) {
      sum += num;
    }
    
    if (sum % k)
      return false;
    
    int target = sum / k;
    
    int all = (1 << nums.size()) - 1;
    
    vector<char> memo (all, -1);
    
    return solve(nums, k, target, all, memo, 0, 0);
  }
  
private:
  bool solve(vector<int>& nums, int k, int target, int all, vector<char>& memo, int usedMask, int subsetSum) {
    if (subsetSum == target) {
      k--;
      subsetSum = 0;
    }
    
    if (usedMask == all)
      return k == 0 and subsetSum == 0;
    
    if (memo[usedMask] != -1)
      return memo[usedMask];
    
    for (int i = 0; i < nums.size(); i++) {
      if ((usedMask & (1 << i)) == 0 and subsetSum + nums[i] <= target and solve(nums, k, target, all, memo, (usedMask | (1 << i)), subsetSum + nums[i]))
        return memo[usedMask] = true;
    }
    
    return memo[usedMask] = false;
  }
};