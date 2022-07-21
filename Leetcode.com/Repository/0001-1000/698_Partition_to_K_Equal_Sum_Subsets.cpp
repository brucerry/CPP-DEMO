// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * 2^n)
// space: O(2^n)

class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    for (const int& num : nums)
      sum += num;
    
    if (sum % k)
      return false;
    
    sort(nums.rbegin(), nums.rend()); // slightly speed optimized
    
    int n = nums.size();
    int target = sum / k;
    int all = (1 << n) - 1;
    vector<char> memo (all + 1, -1);
    return solve(nums, k, target, all, memo, 0, 0);
  }
  
private:
  bool solve(vector<int>& nums, int k, int target, int all, vector<char>& memo, int subsum, int usedMask) {
    if (target == subsum) {
      k--;
      subsum = 0;
    }
    
    if (all == usedMask)
      return k == 0 and subsum == 0;
    
    if (memo[usedMask] != -1)
      return memo[usedMask];
    
    for (int i = 0; i < nums.size(); i++) {
      if ((usedMask & (1 << i)) == 0 and nums[i] + subsum <= target and solve(nums, k, target, all, memo, nums[i] + subsum, usedMask | (1 << i)))
        return memo[usedMask] = true;
    }
    
    return memo[usedMask] = false;
  }
};