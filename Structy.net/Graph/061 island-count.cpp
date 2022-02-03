#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


bool explore(std::vector<std::vector<char>> grid, int r, int c, unordered_set<string> &visited) {
  if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return false;
  string pos = to_string(r) + ',' + to_string(c);
  if (visited.count(pos)) return false;
  visited.insert(pos);
  if (grid[r][c] == 'W') return false;
  
  explore(grid, r+1, c, visited);
  explore(grid, r-1, c, visited);
  explore(grid, r, c+1, visited);
  explore(grid, r, c-1, visited);

  return true;
}


int islandCount(std::vector<std::vector<char>> grid) {
  unordered_set<string> visited;
  int count = 0;
  
  for (int r = 0; r < grid.size(); r++) {
    for (int c = 0; c < grid[0].size(); c++) {
      if (explore(grid, r, c, visited)) count++;
    }
  }
  
  return count;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}