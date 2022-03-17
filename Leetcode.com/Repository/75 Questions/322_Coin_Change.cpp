// https://leetcode.com/problems/coin-change/

#include <vector>
using namespace std;

class Solution {
public:
  // time: O(a * c)
  // space: O(a)
  int coinChange(vector<int>& coins, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      int mini = INT_MAX;
      for (int& coin : coins) {
        int remain = i - coin;
        if (remain >= 0) {
          mini = min(mini, dp[remain]);
        }
      }
      dp[i] = mini == INT_MAX ? mini : mini + 1;
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};