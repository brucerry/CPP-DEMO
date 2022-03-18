// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;
    int left = 0; // buy here
    int right = 1; // sell here

    while (right < prices.size()) {
      if (prices[left] >= prices[right]) {
        left = right;
      }
      else {
        ans = max(ans, prices[right] - prices[left]);
      }
      right++;
    }

    return ans;
  }
};