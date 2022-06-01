// https://leetcode.com/problems/number-of-islands/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int island = 0;
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (exploreIsland(grid, r, c))
          island++;
      }
    }
    
    return island;
  }
  
private:
  bool exploreIsland(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == '0')
      return false;
    
    grid[r][c] = '0';
    
    exploreIsland(grid, r+1, c);
    exploreIsland(grid, r-1, c);
    exploreIsland(grid, r, c+1);
    exploreIsland(grid, r, c-1);
    
    return true;
  }
};