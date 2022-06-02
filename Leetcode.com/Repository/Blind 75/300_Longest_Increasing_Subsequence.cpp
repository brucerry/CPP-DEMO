// https://leetcode.com/problems/longest-increasing-subsequence/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)
class BinarySearch {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    
    for (const int& num : nums) {
      int pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
      if (pos == dp.size())
        dp.emplace_back(num);
      else
        dp[pos] = num;
    }
    
    return dp.size();
  }
};

// time: O(n^2)
// space: O(n)
class NestedLoops {
public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp (n, 1);
    int result = 0;
    
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] < nums[j])
          dp[i] = max(dp[i], 1 + dp[j]);
      }
      result = max(result, dp[i]);
    }
    
    return result;
  }
};