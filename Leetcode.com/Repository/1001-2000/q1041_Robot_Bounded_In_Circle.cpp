// https://leetcode.com/problems/robot-bounded-in-circle/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool isRobotBounded(string& instructions) {
    int x = 0, y = 0;
    int moveX = 0, moveY = 1;
    
    for (const char& c : instructions) {
      if (c == 'L') {
        int tmp = moveX;
        moveX = -moveY;
        moveY = tmp;
      }
      else if (c == 'R') {
        int tmp = moveX;
        moveX = moveY;
        moveY = -tmp;
      }
      else {
        x += moveX;
        y += moveY;
      }
    }
    
    return (x == 0 and y == 0) or moveX != 0 or moveY != 1;
  }
};