// https://leetcode.com/problems/out-of-boundary-paths/

// time: O(m * n * maxMove)
// space: O(m * n)
class BottomUpDP {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    int dp[50][50] {};
    dp[startRow][startColumn] = 1;
    
    int count = 0, mod = 1e9 + 7;
    for (int move = 1; move <= maxMove; move++) {
      int tmp[50][50] {};
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (r == 0)
            count = (count + dp[r][c]) % mod;
          if (c == 0)
            count = (count + dp[r][c]) % mod;
          if (r == m - 1)
            count = (count + dp[r][c]) % mod;
          if (c == n - 1)
            count = (count + dp[r][c]) % mod;
          int left = c ? dp[r][c-1] : 0;
          int right = c + 1 < n ? dp[r][c+1] : 0;
          int up = r ? dp[r-1][c] : 0;
          int down = r + 1 < m ? dp[r+1][c] : 0;
          tmp[r][c] = ((left + right) % mod + (up + down) % mod) % mod;
        }
      }
      memcpy(dp, tmp, sizeof(tmp));
    }
    
    return count;
  }
};

// time: O(m * n * maxMove)
// space: O(m * n * maxMove)
class TopDownMemo {
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    long memo[50][50][51];
    memset(memo, -1, sizeof(memo));
    return solve(m, n, maxMove, startRow, startColumn, memo);
  }
  
private:
  long solve(int rows, int cols, int maxMove, int r, int c, long (*memo)[50][51]) {
    if (r < 0 or r >= rows or c < 0 or c >= cols)
      return 1;
    
    if (maxMove == 0)
      return 0;
    
    if (memo[r][c][maxMove] != -1)
      return memo[r][c][maxMove];
    
    memo[r][c][maxMove] = solve(rows, cols, maxMove-1, r+1, c, memo) +
                          solve(rows, cols, maxMove-1, r-1, c, memo) +
                          solve(rows, cols, maxMove-1, r, c+1, memo) +
                          solve(rows, cols, maxMove-1, r, c-1, memo);
    
    return memo[r][c][maxMove] %= 1000000007;
  }
};