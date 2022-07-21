// https://leetcode.com/problems/paint-house-ii/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    int houses = costs.size();
    int colors = houses ? costs[0].size() : 0;

    int min1 = 0, min2 = 0, min1Color = -1;
    for (int h = 0; h < houses; h++) {
      int m1 = INT_MAX, m2 = INT_MAX, m1Color = -1;
      for (int c = 0; c < colors; c++) {
        int cost = costs[h][c] + (c == min1Color ? min2 : min1);
        if (cost < m1) {
          m2 = m1;
          m1 = cost;
          m1Color = c;
        }
        else if (cost < m2)
          m2 = cost;
      }

      min1 = m1;
      min2 = m2;
      min1Color = m1Color;
    }

    return min1;
  }
};