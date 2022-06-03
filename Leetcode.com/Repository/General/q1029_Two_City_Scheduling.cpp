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
    
    vector<pair<int, int>> diffs (n); // cost A - cost B, index
    for (int i = 0; i < n; i++) {
      int a = costs[i][0];
      int b = costs[i][1];
      diffs[i] = { a - b, i };
    }
    sort(diffs.begin(), diffs.end());
    
    int half = n >> 1;
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
      auto& [ _, idx ] = diffs[i];
      if (i < half)
        totalCost += costs[idx][0];
      else
        totalCost += costs[idx][1];
    }
    
    return totalCost;
  }
};