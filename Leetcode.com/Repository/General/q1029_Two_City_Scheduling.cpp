// https://leetcode.com/problems/two-city-scheduling/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int n = costs.size();
    
    vector<pair<int, int>> diffs (n);
    for (int i = 0; i < n; i++)
      diffs[i] = { costs[i][0] - costs[i][1], i };
    
    sort(diffs.begin(), diffs.end());
    
    int totalCost = 0;
    int half = n >> 1;
    
    for (int i = 0; i < n; i++) {
      auto& [ _, j ] = diffs[i];
      if (i < half)
        totalCost += costs[j][0];
      else
        totalCost += costs[j][1];
    }
    
    return totalCost;
  }
};