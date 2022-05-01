// https://leetcode.com/problems/robot-bounded-in-circle/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool isRobotBounded(string& instructions) {
    int dirX = 0, dirY = 1;
    int x = 0, y = 0;
    
    for (const char& c : instructions) {
      if (c == 'G') {
        x += dirX;
        y += dirY;
      }
      else if (c == 'L') {
        int tmp = dirX;
        dirX = -dirY;
        dirY = tmp;
      }
      else {
        int tmp = dirX;
        dirX = dirY;
        dirY = -tmp;
      }
    }
    
    return (x == 0 and y == 0) or not(dirX == 0 and dirY == 1);
  }
};