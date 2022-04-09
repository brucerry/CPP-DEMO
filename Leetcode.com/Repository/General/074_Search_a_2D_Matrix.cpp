// https://leetcode.com/problems/search-a-2d-matrix/

#include <vector>
using namespace std;

// time: O(log(r) + log(c))
// space: O(1)

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int top = 0, bottom = matrix.size() - 1;
    int row = -1;
    
    while (top <= bottom) {
      int mid = top + ((bottom - top) >> 1);
      
      if (matrix[mid].back() < target)
        top = mid + 1;
      else if (matrix[mid].front() > target)
        bottom = mid - 1;
      else {
        row = mid;
        break;
      }
    }
    
    if (row == -1)
      return false;
    
    int l = 0, r = matrix[0].size() - 1;
    
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      
      if (matrix[row][m] < target)
        l = m + 1;
      else if (matrix[row][m] > target)
        r = m - 1;
      else
        return true;
    }
    
    return false;
  }
};