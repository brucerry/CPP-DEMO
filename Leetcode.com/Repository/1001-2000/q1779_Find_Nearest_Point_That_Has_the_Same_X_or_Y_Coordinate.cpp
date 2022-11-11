// https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

#include <vector>
#include <cmath>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int result = -1, minDist = INT_MAX;
    for (int i = 0; i < points.size(); i++) {
      int x2 = points[i][0], y2 = points[i][1];
      if (x == x2 or y == y2) {
        int dist = abs(x - x2) + abs(y - y2);
        if (dist < minDist) {
          result = i;
          minDist = dist;
        }
      }
    }
    return result;
  }
};