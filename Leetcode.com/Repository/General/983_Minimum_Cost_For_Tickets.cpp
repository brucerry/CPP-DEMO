// https://leetcode.com/problems/minimum-cost-for-tickets/

#include <vector>
using namespace std;

// n = len of days
// time: O(n)
// space: O(n)

class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp (days.size(), INT_MAX);

    for (int i = days.size() - 1; i >= 0; i--) {
      for (int c = 0; c < costs.size(); c++) {
        int day = c == 0 ? 1 : c == 1 ? 7 : 30;
        int j = i;
        while (j < days.size() && days[j] < days[i] + day) j++;
        dp[i] = min(dp[i], costs[c] + (j < days.size() && dp[j] != INT_MAX ? dp[j] : 0));
      }
    }

    return dp[0];
  }
};