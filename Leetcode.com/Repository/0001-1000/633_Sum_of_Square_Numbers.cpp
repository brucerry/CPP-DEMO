// https://leetcode.com/problems/sum-of-square-numbers/

#include <cmath>

// time: O(log(c))
// space: O(1)

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long l = 0, r = sqrt(c); l <= r; ) {
            long val = l * l + r * r;
            if (val < c)
                l++;
            else if (val > c)
                r--;
            else
                return true;
        }
        return false;
    }
};