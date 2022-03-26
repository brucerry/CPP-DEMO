// https://leetcode.com/problems/max-area-of-island/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
private:
  int explore(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 0;

    grid[r][c] = 0;

    return 1 + explore(grid, r+1, c) + explore(grid, r, c+1) + explore(grid, r, c-1) + explore(grid, r-1, c);
  }

public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        ans = max(ans, explore(grid, r, c));        
      }
    }

    return ans;
  }
};