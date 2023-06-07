// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

// time: O(1)
// space: O(1)

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for (int i = 0; i < 30; i++) {
            int count = 0;
            count += (a & (1 << i)) > 0;
            count += (b & (1 << i)) > 0;
            if ((c & (1 << i)) == 0) {
                res += count;
            }
            else {
                res += count == 0;
            }
        }
        return res;
    }
};