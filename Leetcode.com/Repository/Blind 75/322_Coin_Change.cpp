// https://leetcode.com/problems/coin-change/

#include <vector>
using namespace std;

// time: O(a * n)
// space: O(a)

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp (amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int a = 0; a <= amount; a++) {
      for (const int& coin : coins) {
        if (a >= coin) {
          dp[a] = min(dp[a], dp[a - coin] + 1);
        }
      }
    }
    
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};