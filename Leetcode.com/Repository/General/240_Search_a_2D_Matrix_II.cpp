// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <vector>
using namespace std;

// time: O(r + c)
// space: O(1)

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0, c = matrix[0].size() - 1;
    
    while (r < matrix.size() and c >= 0) {
      if (matrix[r][c] < target)
        r++;
      else if (matrix[r][c] > target)
        c--;
      else
        return true;
    }
    
    return false;
  }
};