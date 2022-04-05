// https://leetcode.com/problems/burst-balloons/

#include <vector>
using namespace std;

// time: O(n^3)
// space: O(n^2)

class Solution {
private:
  int maxCoins(vector<int>& nums, int left, int right, vector<vector<int>> &dp){
    if (left > right) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    for (int i = left; i <= right; i++) {      
      int leftCoin = left - 1 < 0 ? 1 : nums[left - 1];
      int rightCoin = right + 1 >= nums.size() ? 1 : nums[right + 1];
      int totalCoins = leftCoin * rightCoin * nums[i];
      totalCoins += maxCoins(nums, left, i - 1, dp) + maxCoins(nums, i + 1, right, dp);
      dp[left][right] = max(dp[left][right], totalCoins);
    }

    return dp[left][right];
  }

public:
  int maxCoins(vector<int>& nums) {
    vector<vector<int>> dp (nums.size(), vector<int>(nums.size(), -1));
    return maxCoins(nums, 0, nums.size() - 1, dp);
  }
};