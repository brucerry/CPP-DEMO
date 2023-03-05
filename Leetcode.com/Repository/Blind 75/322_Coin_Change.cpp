// https://leetcode.com/problems/coin-change/

#include <vector>
using namespace std;

// time: O(amount * n)
// space: O(amount)

class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    int dp[10001] = {};
    fill(begin(dp) + 1, end(dp), amount + 1);
    
    for (const int& coin : coins) {
        for (int a = 1; a <= amount; a++) {
            if (a >= coin)
                dp[a] = min(dp[a], dp[a - coin] + 1);
        }
    }
    
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};