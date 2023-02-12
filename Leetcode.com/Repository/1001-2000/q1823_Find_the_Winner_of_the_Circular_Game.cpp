// https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// time: O(n)
// space: O(1)

class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int ppl = 1; ppl <= n; ppl++) {
            res = (res + k) % ppl;
        }
        return res + 1;
    }
};