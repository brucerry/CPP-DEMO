// https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <vector>
using namespace std;

// time: O(r * c) for constructor, O(1) for sumRegion()
// space: O(r * c)

class NumMatrix {
public:
  NumMatrix(vector<vector<int>>& matrix) {
    prefix = matrix;
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    for (int r = 0; r < rows; r++) {
      int leftval = 0;
      for (int c = 0; c < cols; c++) {
        leftval += c - 1 < 0 ? 0 : matrix[r][c-1];
        int topval = r - 1 < 0 ? 0 : prefix[r-1][c];
        prefix[r][c] += leftval + topval;
      }
    }
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    int left = col1 - 1 < 0 ? 0 : prefix[row2][col1-1];
    int top = row1 - 1 < 0 ? 0 : prefix[row1-1][col2];
    int topleft = row1 - 1 < 0 or col1 - 1 < 0 ? 0 : prefix[row1-1][col1-1];
    return prefix[row2][col2] - left - top + topleft;
  }
  
private:
  vector<vector<int>> prefix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */