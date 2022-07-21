// https://leetcode.com/problems/unique-paths-ii/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = cols - 1; c >= 0; c--) {
        if ((r == rows - 1 and c == cols - 1) or obstacleGrid[r][c])
          obstacleGrid[r][c] = !obstacleGrid[r][c];
        else {
          int rightVal = c + 1 == cols ? 0 : obstacleGrid[r][c+1];
          int downVal = r + 1 == rows ? 0 : obstacleGrid[r+1][c];
          obstacleGrid[r][c] = rightVal > INT_MAX - downVal ? 0 : rightVal + downVal;
        }
      }
    }
    
    return obstacleGrid[0][0];
  }
};