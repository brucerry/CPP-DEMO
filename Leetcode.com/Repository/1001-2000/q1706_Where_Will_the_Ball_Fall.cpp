// https://leetcode.com/problems/where-will-the-ball-fall/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  vector<int> findBall(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<int> result (cols, -1);
    for (int i = 0; i < cols; i++) {
      int r, c;
      for (r = 0, c = i; r < rows; r++) {
        if ((c == 0 and grid[r][c] == -1) or
            (c == cols - 1 and grid[r][c] == 1) or
            (0 <= c and c < cols - 1 and grid[r][c] == 1 and grid[r][c+1] == -1) or
            (1 <= c and c < cols and grid[r][c-1] == 1 and grid[r][c] == -1))
          break;
        c += grid[r][c];
      }
      if (r == rows)
        result[i] = c;
    }
    return result;
  }
};