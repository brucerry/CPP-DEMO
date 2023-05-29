// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

// time: O(1)
// space: O(1)

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0, bit = 1;
        for (int i = 0; i < 31; i++) {
            res += (start & bit) != (goal & bit);
            bit <<= 1;
        }
        return res;
    }
};