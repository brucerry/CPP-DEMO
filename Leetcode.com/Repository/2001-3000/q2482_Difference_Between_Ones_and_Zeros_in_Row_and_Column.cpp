// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r + c)

class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    
    vector<int> onesRow (rows), onesCol (cols);
    vector<int> zerosRow (rows), zerosCol (cols);
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c]) {
          onesRow[r]++;
          onesCol[c]++;
        }
        else {
          zerosRow[r]++;
          zerosCol[c]++;
        }
      }
    }
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        grid[r][c] = onesRow[r] + onesCol[c] - zerosRow[r] - zerosCol[c];
      }
    }
    
    return grid;
  }
};