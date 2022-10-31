// https://leetcode.com/problems/toeplitz-matrix/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size(), cols = matrix[0].size();
    for (int r = 1; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        if (matrix[r-1][c-1] != matrix[r][c])
          return false;
      }
    }
    return true;
  }
};