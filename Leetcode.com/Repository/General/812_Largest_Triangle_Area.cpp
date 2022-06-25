// https://leetcode.com/problems/largest-triangle-area/

#include <vector>
using namespace std;

// time: O(n^3)
// space: O(1)

class Solution {
public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double area = 0;
    for (const auto& p1 : points) {
      for (const auto& p2 : points) {
        for (const auto& p3 : points) {
          int x1 = p1[0], y1 = p1[1];
          int x2 = p2[0], y2 = p2[1];
          int x3 = p3[0], y3 = p3[1];
          area = max(area, 0.5 * abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x3 * y2 - x2 * y1));
        }
      }
    }
    return area;
  }
};