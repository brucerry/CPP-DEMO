// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

// time: O(steps^2)
// space: O(steps^2)

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int memo[501][501];
        memset(memo, -1, sizeof(memo));
        return solve(steps, arrLen, memo, 0);
    }

private:
    int solve(int steps, int arrLen, int memo[501][501], int i) {
        if (i < 0 or i >= arrLen or steps < 0)
            return 0;
            
        if (steps == 0 and i == 0)
            return 1;

        int& res = memo[i][steps];
        if (res != -1)
            return res;

        int stay = solve(steps - 1, arrLen, memo, i);
        int right = solve(steps - 1, arrLen, memo, i + 1);
        int left = solve(steps - 1, arrLen, memo, i - 1);
        return res = ((stay + right) % 1000000007 + left) % 1000000007;
    }
};