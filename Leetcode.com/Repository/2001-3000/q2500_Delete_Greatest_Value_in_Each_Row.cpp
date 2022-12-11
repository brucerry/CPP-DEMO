// https://leetcode.com/problems/delete-greatest-value-in-each-row/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r * c^2)
// space: O(1)

class Solution {
public:
  int deleteGreatestValue(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size(), res = 0;
    for (int i = 0; i < cols; i++) {
      int deleted_max = 0;
      for (int r = 0; r < rows; r++) {
        auto it = max_element(grid[r].begin(), grid[r].end());
        deleted_max = max(deleted_max, *it);
        *it = 0;
      }
      res += deleted_max;
    }
    return res;
  }
};