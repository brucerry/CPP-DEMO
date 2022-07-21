// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <vector>
using namespace std;

// time: O(r + c)
// space: O(1)

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int r = 0, c = cols - 1;
    while (r < rows and c >= 0) {
      if (target < matrix[r][c])
        c--;
      else if (target > matrix[r][c])
        r++;
      else
        return true;
    }
    return false;
  }
};