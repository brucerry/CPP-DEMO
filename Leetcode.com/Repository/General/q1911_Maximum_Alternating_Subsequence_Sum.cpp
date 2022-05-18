// https://leetcode.com/problems/maximum-alternating-subsequence-sum/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class Solution {
public:
  long long maxAlternatingSum(vector<int>& nums) {
    long long sumEven = 0, sumOdd = 0;
    
    for (const int& num : nums) {
      long long tmpEven = max(sumEven, sumOdd + num);
      long long tmpOdd = max(sumOdd, sumEven - num);
      
      sumEven = tmpEven;
      sumOdd = tmpOdd;
    }
    
    return sumEven;
  }
};

// time: O(n)
// space: O(n)
class TopDownMemo {
public:
  long long maxAlternatingSum(vector<int>& nums) {
    vector<vector<long long>> memo (2, vector<long long>(nums.size(), -1));
    return solve(nums, 0, true, memo);
  }
  
private:
  long long solve(vector<int>& nums, int i, bool even, vector<vector<long long>>& memo) {
    if (i == nums.size())
      return 0;
    
    if (memo[even][i] != -1)
      return memo[even][i];
    
    int sum = even ? nums[i] : -nums[i];
    return memo[even][i] = max(sum + solve(nums, i + 1, !even, memo), solve(nums, i + 1, even, memo));
  }
};