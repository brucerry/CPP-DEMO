// https://leetcode.com/problems/domino-and-tromino-tiling/

// time: O(n)
// space: O(n)

class Solution {
public:
  int numTilings(int n) {
    int dp[1001] = { 1, 1, 2 }, mod = 1e9 + 7;
    for (int i = 3; i <= n; i++) {
      dp[i] = (2 * dp[i-1] % mod + dp[i-3]) % mod;
    }
    return dp[n];
  }
};