// https://leetcode.com/problems/maximum-alternating-subsequence-sum/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)
class DP {
public:
  long long maxAlternatingSum(vector<int>& nums) {
    long long sumEven = 0, sumOdd = 0;
    for (const int& num : nums) {
      long long tmpEven = sumEven;
      sumEven = max(sumEven, sumOdd + num);
      sumOdd = max(sumOdd, tmpEven - num);
    }
    return sumEven;
  }
};

// time: O(n)
// space: O(n)
class TopDownMemo {
public:
  long long maxAlternatingSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<long long>> memo (2, vector<long long>(n, INT_MIN));
    return solve(nums, true, 0, memo);
  }
  
private:
  long long solve(vector<int>& nums, bool even, int i, vector<vector<long long>>& memo) {
    if (i == nums.size())
      return 0;
    
    if (memo[even][i] != INT_MIN)
      return memo[even][i];
    
    int num = even ? nums[i] : -nums[i];
    long long apply = num + solve(nums, !even, i + 1, memo);
    long long skip = solve(nums, even, i + 1, memo);
    return memo[even][i] = max(apply, skip);
  }
};