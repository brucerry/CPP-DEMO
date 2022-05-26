// https://leetcode.com/problems/maximal-square/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(c)
class DP_1D {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int maxsqrlen = 0;
    vector<int> dp (cols + 1);
    for (int r = 1; r <= rows; r++) {
      int prev = 0;
      
      for (int c = 1; c <= cols; c++) {
        int tmp = dp[c];
        
        if (matrix[r-1][c-1] == '1') {
          dp[c] = 1 + min({ prev, dp[c], dp[c-1] });
          maxsqrlen = max(maxsqrlen, dp[c]);
        }
        else
          dp[c] = 0;
        
        prev = tmp;
      }
    }
    
    return maxsqrlen * maxsqrlen;
  }
};

// time: O(r * c)
// space: O(r * c)
class DP_2D {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int maxsqrlen = 0;
    vector<vector<int>> dp (rows + 1, vector<int>(cols + 1));
    for (int r = 1; r <= rows; r++) {
      for (int c = 1; c <= cols; c++) {
        if (matrix[r-1][c-1] == '1') {
          dp[r][c] = 1 + min({ dp[r-1][c-1], dp[r-1][c], dp[r][c-1] });
          maxsqrlen = max(maxsqrlen, dp[r][c]);
        }
      }
    }
    
    return maxsqrlen * maxsqrlen;
  }
};