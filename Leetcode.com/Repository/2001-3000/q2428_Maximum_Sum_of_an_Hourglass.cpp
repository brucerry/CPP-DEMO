// https://leetcode.com/problems/maximum-sum-of-an-hourglass/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  int maxSum(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int result = 0;
    
    for (int r = 0; r < rows - 3 + 1; r++) {
      for (int c = 0; c < cols - 3 + 1; c++) {
        int sum = 0;
        for (int i = r; i < r + 3; i++) {
          for (int j = c; j < c + 3; j++) {
            sum += grid[i][j];
          }
        }
        sum -= grid[r+1][c];
        sum -= grid[r+1][c+2];
        result = max(result, sum);
      }
    }
    
    return result;
  }
};