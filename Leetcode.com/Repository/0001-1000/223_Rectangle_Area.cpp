// https://leetcode.com/problems/rectangle-area/

// time: O(1)
// space: O(1)

class Solution {
public:
  int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int area_a = area(ax1, ay1, ax2, ay2);
    int area_b = area(bx1, by1, bx2, by2);
    return area_a + area_b - overlappedArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
  }

private:
  int area(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (y2 - y1);
  }

  bool isOverlapped(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    return (ax1 < bx2 and bx1 < ax2) and (ay1 < by2 and by1 < ay2);
  }

  int overlappedArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    return isOverlapped(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2) ?
           area(max(ax1, bx1), max(ay1, by1), min(ax2, bx2), min(ay2, by2)) :
           0;
  }
};