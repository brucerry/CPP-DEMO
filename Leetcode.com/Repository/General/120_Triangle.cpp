// https://leetcode.com/problems/triangle/

#include <vector>
using namespace std;

// r = # of rows
// n = # of elements (area of triangle)
// time: O(n)
// space: O(r)

class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<int> dp = triangle.back();
    
    for (int r = triangle.size() - 2; r >= 0; r--) {
      for (int c = 0; c < triangle[r].size(); c++) {
        dp[c] = triangle[r][c] + min(dp[c], dp[c+1]);
      }
    }
    
    return dp[0];
  }
};