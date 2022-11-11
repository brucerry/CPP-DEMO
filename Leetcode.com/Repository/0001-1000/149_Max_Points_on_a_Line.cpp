// https://leetcode.com/problems/max-points-on-a-line/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int maxPoints(vector<vector<int>>& pts) {
    unordered_map<double, int> counts; // slope, count
    int n = pts.size(), result = 0;
    for (int i = 0; i < n; i++) {
      counts = {};
      double x1 = pts[i][0], y1 = pts[i][1];
      for (int j = 0; j < n; j++) {
        if (i != j) {
          double x2 = pts[j][0], y2 = pts[j][1];
          double slope = (y1 - y2) / (x1 - x2);
          result = max(result, ++counts[slope]);
        }
      }
    }
    return result + 1;
  }
};