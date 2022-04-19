// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<vector<int>> dp (rows, vector<int>(cols, 0));
    
    int ans = 0;
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        ans = max(ans, solve(matrix, r, c, -1, dp));
      }
    }
    
    return ans;
  }
  
private:
  int solve(vector<vector<int>>& matrix, int r, int c, int prev, vector<vector<int>>& dp) {
    if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] <= prev)
      return 0;
    
    if (dp[r][c])
      return dp[r][c];
    
    return dp[r][c] = 1 + max({ solve(matrix, r+1, c, matrix[r][c], dp),
                                solve(matrix, r-1, c, matrix[r][c], dp),
                                solve(matrix, r, c+1, matrix[r][c], dp),
                                solve(matrix, r, c-1, matrix[r][c], dp) });
  }
};