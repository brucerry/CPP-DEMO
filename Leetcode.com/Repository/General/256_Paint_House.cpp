// https://leetcode.com/problems/paint-house/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r)
// space: O(1)

class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    for (int r = 1; r < costs.size(); r++) {
      costs[r][0] += min(costs[r-1][1], costs[r-1][2]);
      costs[r][1] += min(costs[r-1][0], costs[r-1][2]);
      costs[r][2] += min(costs[r-1][0], costs[r-1][1]);
    }

    return *min_element(costs.back().begin(), costs.back().end());
  }
};