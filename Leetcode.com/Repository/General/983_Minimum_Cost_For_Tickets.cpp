// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <vector>
using namespace std;

// n = len of days
// time: O(n)
// space: O(n)

class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    
    vector<int> dp (n, INT_MAX);
    
    for (int i = n - 1; i >= 0; i--) {
      for (int c = 0; c < 3; c++) {
        int day = c == 0 ? 1 : c == 1 ? 7 : 30;
        
        int j = i;
        while (j < n and days[j] < days[i] + day)
          j++;
        
        if (j == n)
          dp[i] = min(dp[i], costs[c]);
        else
          dp[i] = min(dp[i], costs[c] + dp[j]);
      }
    }
    
    return dp[0];
  }
};