// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int profit = 0;
    int hold = -prices[0];
    
    for (int i = 1; i < prices.size(); i++) {
      // sell or not to sell
      profit = max(profit, hold + prices[i] - fee);
      
      // keep holding or hold a new one (buy new)
      hold = max(hold, profit - prices[i]);
    }
    
    return profit;
  }
};