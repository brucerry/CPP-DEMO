// https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/

#include <vector>
#include <cstring>
using namespace std;

// time: O(r * c * (r + c))
// space: O(r * c * (r + c))

class Solution {
public:
  bool hasValidPath(vector<vector<char>>& grid) {
    char memo[100][100][201];
    memset(memo, -1, sizeof(memo));
    return solve(grid, 0, 0, 0, memo);
  }

private:
  bool solve(vector<vector<char>>& grid, int r, int c, int sum, char (*memo)[100][201]) {
    int rows = grid.size(), cols = grid[0].size();
    if (r == rows or c == cols)
      return false;

    sum += grid[r][c] == '(' ? 1 : -1;

    if (r == rows - 1 and c == cols - 1)
      return sum == 0;

    if (sum < 0)
      return false;

    if (memo[r][c][sum] != -1)
      return memo[r][c][sum];

    return memo[r][c][sum] = solve(grid, r+1, c, sum, memo) or solve(grid, r, c+1, sum, memo);
  }
};