// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int maxProfit(vector<int>& prices) {    
    vector<vector<int>> dp (prices.size() + 2, vector<int>(2, 0));
    // rows: days
    // col 0: have no stock
    // col 1: have stock
    
    for (int i = prices.size() - 1; i >= 0; i--) {
      // to buy or cooldown
      dp[i][0] = max(dp[i + 1][1] - prices[i], dp[i + 1][0]);
      
      // to sell or cooldown
      dp[i][1] = max(dp[i + 2][0] + prices[i], dp[i + 1][1]);
    }
    
    return dp[0][0]; // return col 0 at day 0
  }
};