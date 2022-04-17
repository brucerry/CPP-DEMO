// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    cost.emplace_back(0);
    
    for (int i = cost.size() - 4; i >= 0; i--) {
      cost[i] += min(cost[i+1], cost[i+2]);
    }
    
    return min(cost[0], cost[1]);
  }
};