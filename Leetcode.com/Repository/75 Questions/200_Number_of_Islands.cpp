// https://leetcode.com/problems/number-of-islands/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
private:
  int numIslands(vector<vector<char>>& grid, int r, int c, vector<vector<int>>& visited) {
    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return 0;
    if (visited[r][c] != -1) return 0;
    visited[r][c] = 1;
    if (grid[r][c] == '0') return 0;

    numIslands(grid, r+1, c, visited);
    numIslands(grid, r, c+1, visited);
    numIslands(grid, r-1, c, visited);
    numIslands(grid, r, c-1, visited);

    return 1;
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    vector<vector<int>> visited (grid.size(), vector<int>(grid[0].size(), -1));
    int count = 0;

    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (numIslands(grid, r, c, visited) == 1) count++;
      }
    }

    return count;
  }
};