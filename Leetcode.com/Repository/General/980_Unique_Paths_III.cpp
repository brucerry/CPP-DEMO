// https://leetcode.com/problems/unique-paths-iii/

#include <vector>
using namespace std;

// time: O(3^(r * c))
// space: O(r * c)

class Solution {
public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    int empty = 0, sr = 0, sc = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 0)
          empty++;
        else if (grid[r][c] == 1) {
          sr = r;
          sc = c;
          empty++;
        }
      }
    }
    
    int way = 0;
    solve(grid, way, empty, sr, sc);
    return way;
  }
  
private:
  void solve(vector<vector<int>>& grid, int& way, int empty, int r, int c) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] < 0)
      return;
    
    if (grid[r][c] == 2) {
      if (empty == 0)
        way++;
      return;
    }
    
    grid[r][c] = -1;
    
    solve(grid, way, empty-1, r+1, c);
    solve(grid, way, empty-1, r-1, c);
    solve(grid, way, empty-1, r, c+1);
    solve(grid, way, empty-1, r, c-1);
    
    grid[r][c] = 0;
  }
};