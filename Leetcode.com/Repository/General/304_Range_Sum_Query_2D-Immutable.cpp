// https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <vector>
using namespace std;

// time: O(r * c) for constructor, O(1) for sumRegion()
// space: O(r * c)

class NumMatrix {
public:
  NumMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    prefixSum = matrix;
    for (int r = 0; r < rows; r++) {
      int leftPrefix = 0;
      for (int c = 0; c < cols; c++) {
        leftPrefix += c - 1 < 0 ? 0 : matrix[r][c-1];
        int topPrefix = r - 1 < 0 ? 0 : prefixSum[r-1][c];
        prefixSum[r][c] += leftPrefix + topPrefix;
      }
    }
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    int leftPrefix = col1 - 1 < 0 ? 0 : prefixSum[row2][col1-1];
    int topPrefix = row1 - 1 < 0 ? 0 : prefixSum[row1-1][col2];
    int topleftPrefix = row1 - 1 < 0 or col1 - 1 < 0 ? 0 : prefixSum[row1-1][col1-1];
    return prefixSum[row2][col2] - leftPrefix - topPrefix + topleftPrefix;
  }
  
private:
  vector<vector<int>> prefixSum;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */