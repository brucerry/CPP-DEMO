// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/


#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


// tabulation
// class Solution {
// public:
//   int longestIncreasingPath(vector<vector<int>>& matrix, int r, int c, int prevNum, vector<vector<int>>& dp) {
//     if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] <= prevNum) return 0;
//     if (dp[r][c]) return dp[r][c];

//     int count = 1 + max({
//       longestIncreasingPath(matrix, r+1, c, matrix[r][c], dp),
//       longestIncreasingPath(matrix, r-1, c, matrix[r][c], dp),
//       longestIncreasingPath(matrix, r, c+1, matrix[r][c], dp),
//       longestIncreasingPath(matrix, r, c-1, matrix[r][c], dp)});

//     dp[r][c] = count;
//     return count;
//   }

//   int longestIncreasingPath(vector<vector<int>>& matrix) {
//     vector<vector<int>> dp (matrix.size(), vector<int> (matrix[0].size(), 0));
//     int longestPath = 0;

//     for (int r = 0; r < matrix.size(); r++) {
//       for (int c = 0; c < matrix[0].size(); c++) {
//         longestPath = max(longestPath, longestIncreasingPath(matrix, r, c, -1, dp));
//       }
//     }

//     return longestPath;
//   }
// };


// memorization
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix, int r, int c, int prevNum, unordered_map<string, int> &memo) {
    if (r < 0 || r >= matrix.size() || c < 0 || c >= matrix[0].size() || matrix[r][c] <= prevNum) return 0;
    string pos = to_string(r) + ',' + to_string(c);
    if (memo.count(pos)) return memo[pos];

    memo[pos] = 1 + max({
      longestIncreasingPath(matrix, r+1, c, matrix[r][c], memo),
      longestIncreasingPath(matrix, r-1, c, matrix[r][c], memo),
      longestIncreasingPath(matrix, r, c+1, matrix[r][c], memo),
      longestIncreasingPath(matrix, r, c-1, matrix[r][c], memo)});

    return memo[pos];
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    unordered_map<string, int> memo;
    int longestPath = 0;

    for (int r = 0; r < matrix.size(); r++) {
      for (int c = 0; c < matrix[0].size(); c++) {
        longestPath = max(longestPath, longestIncreasingPath(matrix, r, c, -1, memo));
      }
    }

    return longestPath;
  }
};