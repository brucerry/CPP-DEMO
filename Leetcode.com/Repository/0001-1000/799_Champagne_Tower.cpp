// https://leetcode.com/problems/champagne-tower/

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
    double champagneTower(int poured, int qr, int qc) {
        double dp[101][101] {};
        dp[0][0] = poured;
        for (int r = 1; r <= qr; r++) {
            for (int c = 0; c <= r; c++) {
                dp[r][c] += max(0.0, (dp[r-1][c] - 1) / 2);
                dp[r][c] += max(0.0, c - 1 >= 0 ? (dp[r-1][c-1] - 1) / 2 : 0.0);
            }
        }
        return min(1.0, dp[qr][qc]);
    }
};