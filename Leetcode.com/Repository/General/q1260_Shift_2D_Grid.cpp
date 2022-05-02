// https://leetcode.com/problems/shift-2d-grid/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid[0].size();
    int total = rows * cols;
    
    vector<vector<int>> shiftedGrid (rows, vector<int>(cols));
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        int _1Dindex = r * cols + c;
        int new_1Dindex = (_1Dindex + k) % total;
        int newr = new_1Dindex / cols;
        int newc = new_1Dindex % cols;
        shiftedGrid[newr][newc] = grid[r][c];
      }
    }
    
    return shiftedGrid;
  }
};