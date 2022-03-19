// https://leetcode.com/problems/coin-change/

#include <vector>
using namespace std;

class Solution {
public:
  // time: O(a * c)
  // space: O(a)
  int coinChange(vector<int>& coins, int amount) {
    int dp[amount + 1];
    fill(dp, dp + amount + 1, amount + 1);
    dp[0] = 0;

    for (int a = 1; a <= amount; a++) {
      for (int& coin : coins) {
        int remain = a - coin;
        if (remain >= 0) {
          dp[a] = min(dp[a], dp[remain] + 1);
        }
      }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};