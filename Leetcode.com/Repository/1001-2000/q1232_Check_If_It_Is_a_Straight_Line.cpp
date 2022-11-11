// https://leetcode.com/problems/check-if-it-is-a-straight-line/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& cods) {
    for (int i = 2; i < cods.size(); i++) {
      int x0 = cods[i-2][0], y0 = cods[i-2][1];
      int x1 = cods[i-1][0], y1 = cods[i-1][1];
      int x2 = cods[i][0], y2 = cods[i][1];
      if ((y2 - y1) * (x1 - x0) != (y1 - y0) * (x2 - x1))
        return false;
    }
    return true;
  }
};