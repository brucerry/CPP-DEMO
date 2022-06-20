// https://leetcode.com/problems/paint-house/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r)
// space: O(1)

class Solution {
public:
  int minCost(vector<vector<int>> &costs) {
    int houses = costs.size();
    if (houses == 0)
      return 0;

    for (int h = 1; h < houses; h++) {
      int cost0 = min(costs[h-1][1], costs[h-1][2]);
      int cost1 = min(costs[h-1][0], costs[h-1][2]);
      int cost2 = min(costs[h-1][0], costs[h-1][1]);
      costs[h][0] += cost0;
      costs[h][1] += cost1;
      costs[h][2] += cost2;
    }
    return *min_element(costs.back().begin(), costs.back().end());
  }
};