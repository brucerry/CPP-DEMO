// https://leetcode.com/problems/paint-house/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r)
// space: O(1)

class Solution {
public:
  int minCost(vector<vector<int>> &costs) {
    int n = costs.size();

    if (!n)
      return n;

    for (int house = 1; house < n; house++) {
      int cost0 = min(costs[house-1][1], costs[house-1][2]);
      int cost1 = min(costs[house-1][0], costs[house-1][2]);
      int cost2 = min(costs[house-1][0], costs[house-1][1]);

      costs[house][0] += cost0;
      costs[house][1] += cost1;
      costs[house][2] += cost2;
    }

    return *min_element(costs.back().begin(), costs.back().end());
  }
};