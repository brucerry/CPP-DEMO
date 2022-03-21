// https://leetcode.com/problems/maximal-square/

#include <vector>
using namespace std;

class Solution {
public:
  // time: O(r * c)
  // space: O(c)
  int maximalSquare(vector<vector<char>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    int dp[cols + 1];
    memset(dp, 0, sizeof(dp));

    int maxsqlen = 0, prev = 0;
    for (int r = 1; r <= rows; r++) {
      for (int c = 1; c <= cols; c++) {
        int tmp = dp[c];
        if (matrix[r-1][c-1] == '1') {
          dp[c] = 1 + min({dp[c-1], prev, dp[c]});
          maxsqlen = max(maxsqlen, dp[c]);
        }
        else {
          dp[c] = 0;
        }
        prev = tmp;
      }
    }

    return maxsqlen * maxsqlen;
  }
};