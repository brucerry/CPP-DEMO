// https://leetcode.com/problems/longest-increasing-subsequence/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  // time: O(n^2)
  // space: O(n)
  // int lengthOfLIS(vector<int>& nums) {
  //   vector<int> dp (nums.size(), 1);
  //   for (int i = nums.size() - 1; i >= 0; i--) {
  //     for (int j = i + 1; j < dp.size(); j++) {
  //       if (nums[i] < nums[j]) {
  //         dp[i] = max(dp[i], 1 + dp[j]);
  //       }
  //     }
  //   }
  //   return *max_element(dp.begin(), dp.end());
  // }

  // binary search
  // time: O(n * log(n))
  // space: O(n)
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    
    for (const int& num : nums) {
      int pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
      if (pos == dp.size()) dp.emplace_back(num);
      else dp[pos] = num;
    }
    
    return dp.size();
  }
};