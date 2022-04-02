// https://leetcode.com/problems/number-of-islands/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
private:
  bool traverse(vector<vector<char>>& grid, int r, int c) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == '0') return false;
    
    grid[r][c] = '0';
    
    traverse(grid, r+1, c);
    traverse(grid, r-1, c);
    traverse(grid, r, c+1);
    traverse(grid, r, c-1);
    
    return true;
  }
  
public:
  int numIslands(vector<vector<char>>& grid) {
    int ans = 0;
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (traverse(grid, r, c)) ans++;
      }
    }
    
    return ans;
  }
};