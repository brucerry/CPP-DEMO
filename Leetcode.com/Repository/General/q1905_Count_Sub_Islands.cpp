// https://leetcode.com/problems/count-sub-islands/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int rows = grid2.size();
    int cols = grid2[0].size();
    
    vector<vector<char>> visited (rows, vector<char>(cols));
    
    int subIslands = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid2[r][c] and visited[r][c] == 0 and exploreIslands(grid1, grid2, r, c, visited))
          subIslands++;
      }
    }
    
    return subIslands;
  }
  
private:
  bool exploreIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c, vector<vector<char>>& visited) {
    if (r < 0 or r >= grid2.size() or c < 0 or c >= grid2[0].size() or grid2[r][c] == 0 or visited[r][c])
      return true;
    
    visited[r][c] = 1;
    
    bool result = true;
    
    if (grid1[r][c] == 0)
      result = false;
    
    result = exploreIslands(grid1, grid2, r+1, c, visited) and result;
    result = exploreIslands(grid1, grid2, r-1, c, visited) and result;
    result = exploreIslands(grid1, grid2, r, c+1, visited) and result;
    result = exploreIslands(grid1, grid2, r, c-1, visited) and result;
    
    return result;
  }
};