// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class TwoPointers {
public:
  int maxProfit(vector<int>& prices) {
    int l = 0, profit = 0;
    for (int r = 0; r < prices.size(); r++) {
      if (prices[r] < prices[l])
        l = r;
      profit = max(profit, prices[r] - prices[l]);
    }
    return profit;
  }
};

class KeepTrackLowest {
public:
  int maxProfit(vector<int>& prices) {
    int lowest = INT_MAX, profit = 0;
    for (const int& price : prices) {
      lowest = min(lowest, price);
      profit = max(profit, price - lowest);
    }
    return profit;
  }
};