// https://leetcode.com/problems/minimum-path-sum/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        int rightVal = c + 1 == cols ? INT_MAX : grid[r][c+1];
        int downVal = r + 1 == rows ? INT_MAX : grid[r+1][c];
        int choose = min(rightVal, downVal);
        grid[r][c] += choose == INT_MAX ? 0 : choose;
      }
    }
    
    return grid[0][0];
  }
};