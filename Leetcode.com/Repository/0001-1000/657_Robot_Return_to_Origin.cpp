// https://leetcode.com/problems/robot-return-to-origin/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            switch (c) {
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
            }
        }
        return x == 0 and y == 0;
    }
};