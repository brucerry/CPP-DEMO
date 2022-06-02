// https://leetcode.com/problems/set-matrix-zeroes/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    bool setCol0 = false;
    for (int r = 0; r < rows; r++) {
      if (matrix[r][0] == 0)
        setCol0 = true;
      for (int c = 1; c < cols; c++) {
        if (matrix[r][c] == 0)
          matrix[r][0] = matrix[0][c] = 0;
      }
    }
    
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        if (matrix[r][0] == 0 or matrix[0][c] == 0)
          matrix[r][c] = 0;
      }
    }
    
    if (matrix[0][0] == 0) {
      for (int c = 0; c < cols; c++) {
        matrix[0][c] = 0;
      }
    }
    
    if (setCol0) {
      for (int r = 0; r < rows; r++) {
        matrix[r][0] = 0;
      }
    }
  }
};