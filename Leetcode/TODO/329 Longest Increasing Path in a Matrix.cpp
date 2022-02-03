// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


#include <vector>
#include <string>
using namespace std;


class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix, int r, int c, int prevNum, vector<vector<int>>& dp) {
    if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] <= prevNum) return 0;
    if (dp[r][c]) return dp[r][c];

    int count = 1 + max({
      longestIncreasingPath(matrix, r+1, c, matrix[r][c], dp),
      longestIncreasingPath(matrix, r-1, c, matrix[r][c], dp),
      longestIncreasingPath(matrix, r, c+1, matrix[r][c], dp),
      longestIncreasingPath(matrix, r, c-1, matrix[r][c], dp)});

    dp[r][c] = count;
    return count;
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    vector<vector<int>> dp (matrix.size(), vector<int> (matrix[0].size(), 0));
    int longestPath = 0;

    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        longestPath = max(longestPath, longestIncreasingPath(matrix, r, c, -1, dp));
      }
    }

    return longestPath;
  }
};