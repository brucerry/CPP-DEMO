// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/

#include <vector>
using namespace std;

// time: O(r + c)
// space: O(1)

class Solution {
public:
  int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int r = startPos[0], c = startPos[1];
    int end_r = homePos[0], end_c = homePos[1];
    
    int cost = 0;
    while (r != end_r) {
      r += (end_r - r) / abs(end_r - r);
      cost += rowCosts[r];
    }
    
    while (c != end_c) {
      c += (end_c - c) / abs(end_c - c);
      cost += colCosts[c];
    }
    
    return cost;
  }
};