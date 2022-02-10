// https://leetcode.com/problems/longest-increasing-subsequence/

#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
  // time: O(n^2)
  // space: O(n^2)
  // int lengthOfLIS(vector<int> nums, int prevNum, int idx, unordered_map<string, int> &memo) {
  //   if (idx == nums.size()) return 0;

  //   string key = to_string(prevNum) + ',' + to_string(idx);
  //   if (memo.count(key)) return memo[key];

  //   if (prevNum < nums[idx]) {
  //     memo[key] = max(1 + lengthOfLIS(nums, nums[idx], idx + 1, memo), lengthOfLIS(nums, prevNum, idx + 1, memo));
  //   } else {
  //     memo[key] = lengthOfLIS(nums, prevNum, idx + 1, memo);
  //   }

  //   return memo[key];
  // }

public:
  // int lengthOfLIS(vector<int>& nums) {
  //   unordered_map<string, int> memo;
  //   return lengthOfLIS(nums, INT_MIN, 0, memo);
  // }

  // time: O(n^2)
  // space: O(n)
  // int lengthOfLIS(vector<int>& nums) {
  //   vector<int> dp (nums.size(), 1);
  //   int maxlen = 1;
  //   for (int i = dp.size() - 1; i >= 0; i--) {
  //     for (int j = i + 1; j < dp.size(); j++) {
  //       if (nums[i] < nums[j]) {
  //         dp[i] = max(dp[i], 1 + dp[j]);
  //       }
  //     }
  //     maxlen = max(maxlen, dp[i]);
  //   }
  //   return maxlen;
  // }

  // binary search
  // time: O(n * log(n))
  // space: O(n)
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp (1, INT_MIN);
    for (auto num : nums) {
      int pos = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
      if (pos == dp.size()) {
        dp.push_back(num);
      } else {
        dp[pos] = num;
      }
    }
    return dp.size() - 1;
  }
};

int main() {
  vector<int> nums;
  for (int i = 1; i <= 2500; i++) nums.push_back(i);

  Solution sol;
  cout << sol.lengthOfLIS(nums);
}