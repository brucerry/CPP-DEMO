// https://leetcode.com/problems/rectangle-overlap/

#include <vector>
using namespace std;

// time: O(1)
// space: O(1)

class Solution {
public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int rec1x1 = rec1[0], rec1y1 = rec1[1], rec1x2 = rec1[2], rec1y2 = rec1[3];
    int rec2x1 = rec2[0], rec2y1 = rec2[1], rec2x2 = rec2[2], rec2y2 = rec2[3];
    return (rec1x1 < rec2x2 and rec2x1 < rec1x2) and (rec1y1 < rec2y2 and rec2y1 < rec1y2);
  }
};