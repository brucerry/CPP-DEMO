// https://leetcode.com/problems/paint-house-ii/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  int minCostII(vector<vector<int>> &costs) {
    int n = costs.size();
    int k = n ? costs[0].size() : 0;

    int min1 = 0, min2 = 0, colorOfmin1 = -1;
    for (int house = 0; house < n; house++) {
      int m1 = INT_MAX, m2 = INT_MAX, cOm1 = -1;

      for (int color = 0; color < k; color++) {
        int cost = costs[house][color] + (color == colorOfmin1 ? min2 : min1);

        if (cost < m1) {
          m2 = m1;
          m1 = cost;
          cOm1 = color;
        }
        else if (cost < m2)
          m2 = cost;
      }

      min1 = m1;
      min2 = m2;
      colorOfmin1 = cOm1;
    }

    return min1;
  }
};