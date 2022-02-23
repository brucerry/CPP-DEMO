// https://leetcode.com/problems/triangle/

#include <vector>
using namespace std;

// r = # of rows
// n = # of elements
// time: O(n)
// space: O(r)

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int rows = triangle.size();
    vector<int> dp (rows + 1);

    for (int r = rows - 1; r >= 0; r--) {
      for (int c = 0; c < triangle[r].size(); c++) {
        dp[c] = triangle[r][c] + min(dp[c], dp[c+1]);
      }
    }

    return dp[0];
  }
};