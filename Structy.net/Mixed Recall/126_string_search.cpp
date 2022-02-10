#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool explore(std::vector<std::vector<char>> grid, std::string target,
                  int r, int c, int row, int col,
                  int idx, unordered_set<string> &visited) {
  if (r < 0 || r >= row || c < 0 || c >= col) return false;
  if (idx == target.length()) return true;
  if (grid[r][c] != target[idx]) return false;
  string pos = to_string(r) + ',' + to_string(c);
  if (visited.count(pos)) return false;
  visited.insert(pos);
  
  return
  explore(grid, target, r+1, c, row, col, idx+1, visited) ||
  explore(grid, target, r-1, c, row, col, idx+1, visited) ||
  explore(grid, target, r, c+1, row, col, idx+1, visited) ||
  explore(grid, target, r, c-1, row, col, idx+1, visited);
}

bool stringSearch(std::vector<std::vector<char>> grid, std::string target) {
  unordered_set<string> visited;
  int row = grid.size();
  int col = grid[0].size();
  
  for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
      if (explore(grid, target, r, c, row, col, 0, visited)) return true;
    }
  }
  
  return false;
}

void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}