// https://leetcode.com/problems/pass-the-pillow/

// time: O(1)
// space: O(!)

class Solution {
public:
    int passThePillow(int n, int time) {
        // one cycle = go forward and backward to the origin = (n - 1) * 2 seconds
        time %= n * 2 - 2;
        return n - abs(n - 1 - time);
    }
};