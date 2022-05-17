// https://leetcode.com/problems/count-sub-islands/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int rows = grid1.size();
    int cols = grid1[0].size();
    
    int subIsland = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid2[r][c] and exploreSubIsland(grid1, grid2, r, c))
          subIsland++;
      }
    }
    
    return subIsland;
  }
  
private:
  // return 0 if and only if it is not a sub-island (i.e grid1[r][c] == 0 and grid2[r][c] == 1)
  bool exploreSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
    if (r < 0 or r >= grid1.size() or c < 0 or c >= grid1[0].size() or grid2[r][c] == 0)
      return true;
    
    grid2[r][c] = 0;
    
    char result = 1;
    result &= exploreSubIsland(grid1, grid2, r+1, c);
    result &= exploreSubIsland(grid1, grid2, r-1, c);
    result &= exploreSubIsland(grid1, grid2, r, c+1);
    result &= exploreSubIsland(grid1, grid2, r, c-1);
    
    return result & grid1[r][c];
  }
};