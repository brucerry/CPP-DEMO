// https://leetcode.com/problems/search-a-2d-matrix/

#include <vector>
using namespace std;

// time: O(log(r) + log(c))
// space: O(1)

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int rowIndex = -1;
    int l = 0, r = rows - 1;
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      if (target < matrix[m][0])
        r = m - 1;
      else if (target > matrix[m].back())
        l = m + 1;
      else {
        rowIndex = m;
        break;
      }
    }
    
    if (rowIndex == -1)
      return false;
    
    l = 0, r = cols - 1;
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      if (matrix[rowIndex][m] < target)
        l = m + 1;
      else if (matrix[rowIndex][m] > target)
        r = m - 1;
      else
        return true;
    }
    
    return false;
  }
};