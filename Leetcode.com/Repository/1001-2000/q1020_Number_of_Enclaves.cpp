// https://leetcode.com/problems/number-of-enclaves/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int numEnclaves(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if ((min(r, c) == 0 or r == rows - 1 or c == cols - 1) and grid[r][c] == 1)
          mark(grid, r, c);
      }
    }

    int result = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        result += grid[r][c];
      }
    }

    return result;
  }

private:
  void mark(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == 0)
      return;

    grid[r][c] = 0;

    mark(grid, r+1, c);
    mark(grid, r-1, c);
    mark(grid, r, c+1);
    mark(grid, r, c-1);
  }
};