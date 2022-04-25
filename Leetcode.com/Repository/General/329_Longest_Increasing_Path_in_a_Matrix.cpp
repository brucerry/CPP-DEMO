// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {    
    vector<vector<int>> dp (matrix.size(), vector<int>(matrix[0].size()));
    
    int ans = 0;
    
    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        ans = max(ans, solve(matrix, r, c, -1, dp));
      }
    }
    
    return ans;
  }
  
private:
  int solve(vector<vector<int>>& matrix, int r, int c, int prev, vector<vector<int>>& memo) {
    if (r < 0 or r >= matrix.size() or c < 0 or c >= matrix[0].size() or matrix[r][c] <= prev)
      return 0;
    
    if (memo[r][c])
      return memo[r][c];
    
    return memo[r][c] = 1 + max({
      solve(matrix, r+1, c, matrix[r][c], memo),
      solve(matrix, r-1, c, matrix[r][c], memo),
      solve(matrix, r, c+1, matrix[r][c], memo),
      solve(matrix, r, c-1, matrix[r][c], memo)
    });
  }
};