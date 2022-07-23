// https://leetcode.com/problems/maximal-rectangle/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(c)

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<int> leftBounds (cols), rightBounds (cols, cols - 1), heights (cols);
    int area = 0;
    for (int r = 0; r < rows; r++) {
      int rB = cols - 1;
      for (int c = cols - 1; c >= 0; c--) {
        if (matrix[r][c] == '1') {
          rightBounds[c] = min(rightBounds[c], rB);
        }
        else {
          rightBounds[c] = cols - 1;
          rB = c - 1;
        }
      }
      
      int lB = 0;
      for (int c = 0; c < cols; c++) {
        if (matrix[r][c] == '1') {
          leftBounds[c] = max(leftBounds[c], lB);
          heights[c]++;
          area = max(area, heights[c] * (rightBounds[c] - leftBounds[c] + 1));
        }
        else {
          leftBounds[c] = 0;
          heights[c] = 0;
          lB = c + 1;
        }
      }
    }
    
    return area;
  }
};