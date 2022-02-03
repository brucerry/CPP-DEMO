#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


int explore(std::vector<std::vector<char>> grid, int r, int c, unordered_set<string> &visited) {
  if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return -1;
  string pos = to_string(r) + ',' + to_string(c);
  if (visited.count(pos)) return -1;
  visited.insert(pos);
  if (grid[r][c] == 'W') return -1;
  
  int size = 1;
  size += max(0, explore(grid, r+1, c, visited));
  size += max(0, explore(grid, r-1, c, visited));
  size += max(0, explore(grid, r, c+1, visited));
  size += max(0, explore(grid, r, c-1, visited));

  return size;
}



int minimumIsland(std::vector<std::vector<char>> grid) {
  unordered_set<string> visited;
  int minCount = 0;
  
  for (int r = 0; r < grid.size(); r++) {
    for (int c = 0; c < grid[0].size(); c++) {
      int count = explore(grid, r, c, visited);
      if (count != -1) {
        if (minCount == 0 || count < minCount) minCount = count;
      }
    }
  }
  
  return minCount;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}