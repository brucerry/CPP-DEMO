// https://leetcode.com/problems/transpose-matrix/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<vector<int>> tMatrix (cols, vector<int>(rows));
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        tMatrix[c][r] = matrix[r][c];
      }
    }
    
    return tMatrix;
  }
};