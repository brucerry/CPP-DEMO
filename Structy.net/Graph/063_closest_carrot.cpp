#include <vector>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <string>
using namespace std;

bool isValid(int r, int c, int row, int col) {
  return 0 <= r && r < row && 0 <= c && c < col;
}

int closestCarrot(std::vector<std::vector<char>> grid, int startRow, int startCol) {
  int row = grid.size(), col = grid[0].size();
  unordered_set<string> visited;
  queue<tuple<int, int, int>> queue;
  queue.push({startRow, startCol, 0});
  string pos = to_string(startRow) + ',' + to_string(startCol);
  visited.insert(pos);
  
  vector<tuple<int, int>> moves {{0,1}, {0,-1}, {1,0}, {-1,0}};
  
  while (queue.size()) {
    auto [ r, c, dist ] = queue.front();
    queue.pop();
    if (grid[r][c] == 'C') return dist;
    
    for (auto [ dr, dc ] : moves) {
      int newr = dr + r;
      int newc = dc + c;
      string pos = to_string(newr) + ',' + to_string(newc);
      if (isValid(newr, newc, row, col) && visited.count(pos) == 0 && grid[newr][newc] != 'X') {
        queue.push({newr, newc, dist + 1});
        visited.insert(pos);
      }
    }
  }
  
  return -1;
}


void run() {
  // this function behaves as `main()` for the 'run' command
  // you may sandbox in this function, but should not remove it
}