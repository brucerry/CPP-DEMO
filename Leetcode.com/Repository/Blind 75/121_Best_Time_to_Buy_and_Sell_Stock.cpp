// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int l = 0;
    int profit = 0;
    
    for (int r = 0; r < prices.size(); r++) {
      if (prices[r] < prices[l])
        l = r;
      profit = max(profit, prices[r] - prices[l]);
    }
    
    return profit;
  }
};