// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/

// time: O(1)
// space: O(1)

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long op = 1; op <= 60; op++) {
            long x = num1 - op * num2;
            if (__builtin_popcountll(x) <= op and op <= x)
                return op;
        }
        return -1;
    }
};