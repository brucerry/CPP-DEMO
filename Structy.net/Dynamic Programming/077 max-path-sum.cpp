#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int maxPathSum(std::vector<std::vector<int>> grid, int r, int c, unordered_map<string, int> &memo) {
  string pos = to_string(r) + ',' + to_string(c);
  if (memo.count(pos)) return memo[pos];
  if (r == grid.size() || c == grid[0].size()) return 0;
  if (r == grid.size() - 1 && c == grid[0].size() - 1) return grid[r][c];
  
  memo[pos] = grid[r][c] + max(maxPathSum(grid, r+1, c, memo), maxPathSum(grid, r, c+1, memo));
  return memo[pos];
}

int maxPathSum(std::vector<std::vector<int>> grid) {
  unordered_map<string, int> memo;
  return maxPathSum(grid, 0, 0, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}