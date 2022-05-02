// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// time: O(r * c * k)
// space: O(r * c * k)

class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<int>> lives (rows, vector<int>(cols, -1));
    
    queue<tuple<int, int, int, int>> queue; // step, live, r, c
    queue.emplace(0, k, 0, 0);
    
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    while (queue.size()) {
      auto [ step, live, r, c ] = queue.front();
      queue.pop();
      
      if (r == rows - 1 and c == cols - 1)
        return step;
      
      if (grid[r][c])
        live--;
      
      for (const auto& [ dr, dc ] : moves) {
        int newr = dr + r;
        int newc = dc + c;
        if (0 <= newr and newr < rows and 0 <= newc and newc < cols and lives[newr][newc] < live) {
          lives[newr][newc] = live;
          queue.emplace(step + 1, live, newr, newc);
        }
      }
    }
    
    return -1;
  }
};