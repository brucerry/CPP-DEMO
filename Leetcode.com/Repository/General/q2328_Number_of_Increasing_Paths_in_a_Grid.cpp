// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int countPaths(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<int>> memo (rows, vector<int>(cols));
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        explorePath(grid, r, c, -1, memo);
      }
    }
    
    int path = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        path += memo[r][c];
        path %= 1000000007;
      }
    }
    
    return path;
  }
  
private:
  int explorePath(vector<vector<int>>& grid, int r, int c, int prev, vector<vector<int>>& memo) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] <= prev)
      return 0;
    
    if (memo[r][c])
      return memo[r][c];
    
    vector<pair<int, int>> moves { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    
    int count = 1;
    for (const auto& [ dr, dc ] : moves) {
      count += explorePath(grid, r + dr, c + dc, grid[r][c], memo);
      count %= 1000000007;
    }
    
    return memo[r][c] = count;
  }
};