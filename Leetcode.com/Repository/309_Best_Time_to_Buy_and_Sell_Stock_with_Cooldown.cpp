// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
private:
  int maxProfit(vector<int>& prices, int index, int buying, vector<vector<int>>& memo) {
    if (index >= prices.size()) return 0;
    if (memo[index][buying] != INT_MIN) return memo[index][buying];

    int cooldown = maxProfit(prices, index + 1, buying, memo);

    if (buying) {
      int buy = maxProfit(prices, index + 1, !buying, memo) - prices[index];
      memo[index][buying] = max(buy, cooldown);
    }
    else {
      int sell = maxProfit(prices, index + 2, !buying, memo) + prices[index];
      memo[index][buying] = max(sell, cooldown);
    }

    return memo[index][buying];
  }

public:
  int maxProfit(vector<int>& prices) {
    vector<vector<int>> memo (prices.size(), vector<int>(2, INT_MIN));
    return maxProfit(prices, 0, true, memo);
  }
};