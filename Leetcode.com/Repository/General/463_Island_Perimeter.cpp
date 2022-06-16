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
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c])
          return explorePerimeter(grid, r, c);
      }
    }
    
    return -1;
  }
  
private:
  int explorePerimeter(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == 0)
      return 1;
    
    if (grid[r][c] == -1)
      return 0;
    
    grid[r][c] = -1;
    
    return
      explorePerimeter(grid, r+1, c) +
      explorePerimeter(grid, r-1, c) +
      explorePerimeter(grid, r, c+1) +
      explorePerimeter(grid, r, c-1);
  }
};