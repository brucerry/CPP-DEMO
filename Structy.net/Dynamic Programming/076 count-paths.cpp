#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int countPaths(std::vector<std::vector<char>> grid, int r, int c, int row, int col, unordered_map<string, int> &memo) {
  string pos = to_string(r) + ',' + to_string(c);
  if (memo.count(pos)) return memo[pos];
  if (r == row || c == col || grid[r][c] == 'X') return 0;
  if (r == row - 1 && c == col - 1) return 1;
  
  memo[pos] = countPaths(grid, r+1, c, row, col, memo) + countPaths(grid, r, c+1, row, col, memo);
  return memo[pos];
}

int countPaths(std::vector<std::vector<char>> grid) {
  int row = grid.size(), col = grid[0].size();
  unordered_map<string, int> memo;
  return countPaths(grid, 0, 0, row, col, memo);
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}