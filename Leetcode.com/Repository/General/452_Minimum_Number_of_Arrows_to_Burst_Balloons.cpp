// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[1] < b[1];
    });
    
    int shot = 1, arrowPos = points[0][1];
    for (int i = 1; i < points.size(); i++) {
      if (arrowPos >= points[i][0])
        continue;
      shot++;
      arrowPos = points[i][1];
    }
    return shot;
  }
};