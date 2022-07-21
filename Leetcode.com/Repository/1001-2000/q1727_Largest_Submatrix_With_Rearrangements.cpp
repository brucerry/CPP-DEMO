// https://leetcode.com/problems/largest-submatrix-with-rearrangements/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r * c * log(c))
// space: O(c)

class Solution {
public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<int> heights (cols);
    int area = 0;
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (matrix[r][c])
          heights[c]++;
        else
          heights[c] = 0;
      }
      
      vector<int> sortedHeights = heights;
      sort(sortedHeights.begin(), sortedHeights.end());
      
      for (int c = 0; c < cols; c++) {
        area = max(area, sortedHeights[c] * (cols - c));
      }
    }
    
    return area;
  }
};