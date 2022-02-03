#include <vector>
#include <tuple>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

string tag(int r, int c) {
  return to_string(r) + ',' + to_string(c);
}

bool isValid(int r, int c, int row, int col) {
  return 0 <= r && r < row && 0 <= c && c < col;
}

void traverse(std::vector<std::vector<char>> grid,
             vector<tuple<int, int>> &island,
             int r, int c, int row, int col,
             unordered_set<string> &visited) {
  if (!isValid(r, c, row, col)) return;
  if (grid[r][c] == 'W') return;
  string pos = tag(r, c);
  if (visited.count(pos)) return;
  visited.insert(pos);
  
  island.push_back({r, c});
  
  traverse(grid, island, r+1, c, row, col, visited);
  traverse(grid, island, r-1, c, row, col, visited);
  traverse(grid, island, r, c+1, row, col, visited);
  traverse(grid, island, r, c-1, row, col, visited);
}

int bestBridge(std::vector<std::vector<char>> grid) {
  unordered_set<string> visited;
  vector<tuple<int, int>> mainIsland;
  int row = grid.size(), col = grid[0].size();
  
  for (int r = 0; r < row; r++) {
    for (int c = 0; c < col; c++) {
      vector<tuple<int, int>> island;
      traverse(grid, island, r, c, row, col, visited);
      if (island.size()) mainIsland = island;
    }
  }
  
  visited.clear();
  queue<tuple<int, int, int>> queue;
  
  for (auto [ r, c ] : mainIsland) {
    queue.push({r, c, -1});
    visited.insert(tag(r, c));
  }
  
  while (queue.size()) {
    auto [ r, c, dist ] = queue.front();
    queue.pop();
    
    if (grid[r][c] == 'L' && dist != -1) return dist;
    
    vector<tuple<int, int>> moves {{0,1},{0,-1},{1,0},{-1,0}};
    for (auto [ dr, dc ] : moves) {
      int newr = dr + r;
      int newc = dc + c;
      string pos = tag(newr, newc);
      if (isValid(newr, newc, row, col) && visited.count(pos) == 0) {
        visited.insert(pos);
        queue.push({newr, newc, dist+1});
      }
    }
  }
  
  return 999;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}