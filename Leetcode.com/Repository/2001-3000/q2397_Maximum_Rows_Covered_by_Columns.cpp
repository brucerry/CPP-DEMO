// https://leetcode.com/problems/maximum-rows-covered-by-columns/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r)

class Solution {
public:
  int maximumRows(vector<vector<int>>& mat, int COLS) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    vector<int> rowMasks (rows);
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        rowMasks[r] |= mat[r][c] << (cols - c - 1);
      }
    }
    
    int result = 0;
    for (int mask = (1 << COLS) - 1; mask < (1 << cols); mask = nextMask(mask)) {
      int covered_rows = 0;
      for (int r = 0; r < rows; r++) {
        if ((mask | rowMasks[r]) == mask)
          covered_rows++;
      }
      result = max(result, covered_rows);
    }
    
    return result;
  }
  
private:
  int nextMask(int n) {
    int c = (n & -n), r = n + c;
    return (((r ^ n) >> 2) / c) | r;
  }
};