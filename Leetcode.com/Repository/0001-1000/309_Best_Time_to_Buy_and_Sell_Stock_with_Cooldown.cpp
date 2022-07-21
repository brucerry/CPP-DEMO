// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)
class BottomUpDP {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp (2, vector<int>(n + 2));
    // rows: days
    // col 0: have no stock
    // col 1: have stock
    
    for (int i = n - 1; i >= 0; i--) {
      // to buy or cooldown
      dp[0][i] = max(dp[0][i+1], dp[1][i+1] - prices[i]);
      
      // to sell or cooldown
      dp[1][i] = max(dp[1][i+1], dp[0][i+2] + prices[i]);
    }
    
    return dp[0][0]; // return col 0 at day 0
  }
};

// time: O(n)
// space: O(n)
class TopDownMemo {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> memo (2, vector<int>(n, -1));
    return solve(prices, 0, true, memo);
  }
  
private:
  int solve(vector<int>& prices, int i, bool buy, vector<vector<int>>& memo) {
    if (i >= prices.size())
      return 0;
    
    if (memo[buy][i] != -1)
      return memo[buy][i];
    
    int cooldown = solve(prices, i+1, buy, memo);
    
    if (buy)
      return memo[buy][i] = max(-prices[i] + solve(prices, i+1, !buy, memo), cooldown);
    
    return memo[buy][i] = max(prices[i] + solve(prices, i+2, !buy, memo), cooldown);
  }
};