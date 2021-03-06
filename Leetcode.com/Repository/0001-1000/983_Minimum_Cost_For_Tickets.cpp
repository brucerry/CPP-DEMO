// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <vector>
using namespace std;

// n = size of days
// time: O(n * (1 + 7 + 30)) => O(n)
// space: O(n)

class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    
    vector<int> dp (n + 1, INT_MAX);
    dp.back() = 0;
    
    for (int i = n - 1; i >= 0; i--) {
      for (int c = 0; c < 3; c++) {
        int day = c == 0 ? 1 : c == 1 ? 7 : 30;
        int cost = costs[c];
        
        int j = i;
        while (j < n and days[j] < days[i] + day)
          j++;
        
        dp[i] = min(dp[i], dp[j] + cost);
      }
    }
    
    return dp[0];
  }
};