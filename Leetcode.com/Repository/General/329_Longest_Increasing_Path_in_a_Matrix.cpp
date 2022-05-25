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
    
    vector<vector<int>> memo (rows, vector<int>(cols));
    
    int longest = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        longest = max(longest, traversePath(matrix, r, c, -1, memo));
      }
    }
    
    return longest;
  }
  
private:
  int traversePath(vector<vector<int>>& matrix, int r, int c, int prev, vector<vector<int>>& memo) {
    if (r < 0 or r >= matrix.size() or c < 0 or c >= matrix[0].size() or prev >= matrix[r][c])
      return 0;
    
    if (memo[r][c])
      return memo[r][c];
    
    return memo[r][c] = 1 + max({
      traversePath(matrix, r+1, c, matrix[r][c], memo),
      traversePath(matrix, r-1, c, matrix[r][c], memo),
      traversePath(matrix, r, c+1, matrix[r][c], memo),
      traversePath(matrix, r, c-1, matrix[r][c], memo)
    });
  }
};