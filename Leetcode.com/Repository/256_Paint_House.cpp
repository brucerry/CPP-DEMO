// https://leetcode.com/problems/paint-house/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r)
// space: O(1)

class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    vector<int> dp = costs.back();

    for (int r = costs.size() - 2; r >= 0; r--) {
      int cost0 = costs[r][0] + min(dp[1], dp[2]);
      int cost1 = costs[r][1] + min(dp[0], dp[2]);
      int cost2 = costs[r][2] + min(dp[0], dp[1]);
      dp = {cost0, cost1, cost2};
    }

    return *min_element(dp.begin(), dp.end());
  }
};