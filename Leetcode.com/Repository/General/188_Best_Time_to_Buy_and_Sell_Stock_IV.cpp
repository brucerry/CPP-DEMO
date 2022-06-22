// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <vector>
using namespace std;

// time: O(n * k)
// space: O(k)

class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    vector<int> costs (k, INT_MAX);
    vector<int> profits (k);
    
    for (const int& price : prices) {
      for (int i = 0; i < k; i++) {
        costs[i] = min(costs[i], i ? price - profits[i-1] : price);
        profits[i] = max(profits[i], price - costs[i]);
      }
    }
    
    return k ? profits.back() : 0;
  }
};