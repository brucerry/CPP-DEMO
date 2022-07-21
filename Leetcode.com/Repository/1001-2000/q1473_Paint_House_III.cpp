// https://leetcode.com/problems/paint-house-iii/

#include <vector>
using namespace std;

// m = size of houses
// n = number of color
// t = target
// time: O(m * n * t * n)
// space: O(m * n * t)

class Solution {
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    int memo[101][101][21] = {}; // [house][neighborhood][color]
    int result = solve(houses, cost, m, n, target, 0, 0, memo);
    return result > 1e6 ? -1 : result;
  }
  
private:
  int solve(vector<int>& houses, vector<vector<int>>& cost, int houseCount, int colorCount, int neighborhoods,
            int curHouse, int lastColor, int (*memo)[101][21]) {
    
    if (curHouse == houseCount or neighborhoods < 0)
      return neighborhoods == 0 ? 0 : 1e6 + 1;
    
    if (memo[curHouse][neighborhoods][lastColor])
      return memo[curHouse][neighborhoods][lastColor];
    
    if (houses[curHouse])
      return solve(houses, cost, houseCount, colorCount, neighborhoods - (lastColor != houses[curHouse]),
                   curHouse + 1, houses[curHouse], memo);
    
    int totalCost = 1e6 + 1;
    for (int color = 1; color <= colorCount; color++) {
      totalCost = min(totalCost,
                      cost[curHouse][color - 1] +
                      solve(houses, cost, houseCount, colorCount, neighborhoods - (lastColor != color), curHouse + 1, color, memo));
    }
    
    return memo[curHouse][neighborhoods][lastColor] = totalCost;
  }
};