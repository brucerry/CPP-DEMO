// https://leetcode.com/problems/island-perimeter/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<char>> visited (rows, vector<char>(cols));
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c])
          return explorePerimeter(grid, r, c, visited);
      }
    }
    
    return -1;
  }
  
private:
  int explorePerimeter(vector<vector<int>>& grid, int r, int c, vector<vector<char>>& visited) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == 0)
      return 1;
    
    if (visited[r][c])
      return 0;
    
    visited[r][c] = 1;
    
    return
      explorePerimeter(grid, r+1, c, visited) +
      explorePerimeter(grid, r-1, c, visited) +
      explorePerimeter(grid, r, c+1, visited) +
      explorePerimeter(grid, r, c-1, visited);
  }
};