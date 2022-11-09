// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

#include <vector>
using namespace std;

// time: O(r + c)
// space: O(1)

class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    int r = 0, c = cols - 1, count = 0;
    while (r < rows and c >= 0) {
      if (grid[r][c] < 0) {
        count += rows - r;
        c--;
      }
      else
        r++;
    }
    return count;
  }
};