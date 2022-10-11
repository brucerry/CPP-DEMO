// https://leetcode.com/problems/check-if-matrix-is-x-matrix/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  bool checkXMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if ((r == c or r + c + 1 == n) and grid[r][c] == 0)
          return false;
        if (!(r == c or r + c + 1 == n) and grid[r][c])
          return false;
      }
    }
    return true;
  }
};