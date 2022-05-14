// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
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