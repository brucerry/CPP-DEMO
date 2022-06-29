// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

#include <vector>
using namespace std;

// m = size of multipliers
// time: O(m^2)
// space: O(m^2)

class Solution {
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int m = multipliers.size();
    vector<vector<int>> memo (m, vector<int>(m, INT_MIN));
    return solve(nums, multipliers, 0, 0, memo);
  }
  
private:
  int solve(vector<int>& nums, vector<int>& multipliers, int l, int i, vector<vector<int>>& memo) {
    if (i == multipliers.size())
      return 0;
    
    if (memo[l][i] != INT_MIN)
      return memo[l][i];
    
    int chooseLeft = nums[l] * multipliers[i] + solve(nums, multipliers, l + 1, i + 1, memo);
    int r = nums.size() - 1 - (i - l);
    int chooseRight = nums[r] * multipliers[i] + solve(nums, multipliers, l, i + 1, memo);
    
    return memo[l][i] = max(chooseLeft, chooseRight);
  }
};