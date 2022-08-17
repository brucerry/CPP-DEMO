// https://leetcode.com/problems/making-a-large-island/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    
    int largest = 0;
    vector<int> areas { 0, 0 };
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c] == 1) {
          int area = exploreIsland(grid, r, c, areas.size());
          areas.emplace_back(area);
          largest = max(largest, area);
        }
      }
    }
    
    unordered_set<int> colors;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c] == 0) {
          colors = {
            getColor(grid, r+1, c),
            getColor(grid, r-1, c),
            getColor(grid, r, c+1),
            getColor(grid, r, c-1)
          };
          int area = 1;
          for (const int& color : colors)
            area += areas[color];
          largest = max(largest, area);
        }
      }
    }
    
    return largest;
  }
  
private:
  int getColor(vector<vector<int>>& grid, int r, int c) {
    return r < 0 or r >= grid.size() or c < 0 or c >= grid.size() ? 0 : grid[r][c];
  }
  
  int exploreIsland(vector<vector<int>>& grid, int r, int c, int color) {
    if (getColor(grid, r, c) != 1)
      return 0;
    
    grid[r][c] = color;
    
    return 1 +
      exploreIsland(grid, r+1, c, color) +
      exploreIsland(grid, r-1, c, color) +
      exploreIsland(grid, r, c+1, color) +
      exploreIsland(grid, r, c-1, color);
  }
};