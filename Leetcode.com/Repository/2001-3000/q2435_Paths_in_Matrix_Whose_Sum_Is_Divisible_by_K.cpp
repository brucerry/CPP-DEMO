// https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

#include <vector>
using namespace std;

// time: O(r * c * k)
// space: O(r * c * k)

class Solution {
public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid[0].size();
    int mod = 1e9 + 7;
    
    vector<vector<vector<int>>> dp (rows, vector<vector<int>>(cols, vector<int>(k)));
    dp.back().back()[grid.back().back() % k] = 1;
    
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        for (int i = 0; i < k; i++) {
          if (r + 1 < rows)
            dp[r][c][(i + grid[r][c]) % k] = (dp[r][c][(i + grid[r][c]) % k] + dp[r+1][c][i]) % mod;
          if (c + 1 < cols)
            dp[r][c][(i + grid[r][c]) % k] = (dp[r][c][(i + grid[r][c]) % k] + dp[r][c+1][i]) % mod;
        }
      }
    }

    return dp[0][0][0];
  }
};