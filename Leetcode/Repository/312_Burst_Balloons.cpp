// https://leetcode.com/problems/burst-balloons/

#include <vector>
using namespace std;

class Solution {
private:
  int maxCoins(vector<int>& nums, int head, int tail, vector<vector<int>> &dp){
    if (head > tail) return 0;
    if (dp[head][tail] != 0) return dp[head][tail];

    for (int i = head; i <= tail; i++) {      
      int leftCoin = head - 1 < 0 ? 1 : nums[head - 1];
      int rightCoin = tail + 1 >= nums.size() ? 1 : nums[tail + 1];
      int totalCoins = leftCoin * rightCoin * nums[i];
      totalCoins += maxCoins(nums, head, i - 1, dp) + maxCoins(nums, i + 1, tail, dp);
      dp[head][tail] = max(dp[head][tail], totalCoins);
    }

    return dp[head][tail];
  }

public:
  int maxCoins(vector<int>& nums) {
    vector<vector<int>> dp (nums.size(), vector<int>(nums.size(), 0));
    return maxCoins(nums, 0, nums.size() - 1, dp);
  }
};