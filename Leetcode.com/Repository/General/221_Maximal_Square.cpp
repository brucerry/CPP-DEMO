// https://leetcode.com/problems/maximal-square/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(c)

class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<int> dp (cols + 1);
    
    int maxsqrlen = 0;
    
    for (int r = 1; r <= rows; r++) {
      int prev = 0;
      
      for (int c = 1; c <= cols; c++) {
        int tmp = dp[c];
        
        if (matrix[r-1][c-1] == '1') {
          dp[c] = 1 + min({ dp[c], prev, dp[c-1] });
          maxsqrlen = max(maxsqrlen, dp[c]);
        }
        else {
          dp[c] = 0;
        }
        
        prev = tmp;
      }
    }
    
    return maxsqrlen * maxsqrlen;
  }
};