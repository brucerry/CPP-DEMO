// https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

#include <vector>
using namespace std;

// time: O(r * c * r * c)
// space: O(r * c)

class Solution {
public:
  int minDays(vector<vector<int>>& grid) {
    if (numberOfIslands(grid) != 1)
      return 0;
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c]) {
          grid[r][c] = 0;
          if (numberOfIslands(grid) != 1)
            return 1;
          grid[r][c] = 1;
        }
      }
    }
    
    return 2;
  }
  
private:
  int numberOfIslands(vector<vector<int>>& grid) {
    int islands = 0;
    char visited[300][300] {};
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        islands += dfs(grid, r, c, visited);
      }
    }
    return islands;
  }
  
  int dfs(vector<vector<int>>& grid, int r, int c, char (*visited)[300]) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == 0 or visited[r][c])
      return 0;
    
    visited[r][c] = 1;
    
    dfs(grid, r+1, c, visited);
    dfs(grid, r-1, c, visited);
    dfs(grid, r, c+1, visited);
    dfs(grid, r, c-1, visited);
    
    return 1;
  }
};