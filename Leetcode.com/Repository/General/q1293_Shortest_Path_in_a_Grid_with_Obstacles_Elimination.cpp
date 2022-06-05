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
    lives[0][0] = k;
    
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    queue<tuple<int, int, int>> queue; // r, c, live
    queue.emplace(0, 0, k);
    int step = 0;
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        auto [ r, c, live ] = queue.front();
        queue.pop();
        
        if (r == rows - 1 and c == cols - 1)
          return step;
        
        if (grid[r][c])
          live--;
        
        for (const auto& [ dr, dc ] : moves) {
          int newr = r + dr;
          int newc = c + dc;
          if (0 <= newr and newr < rows and 0 <= newc and newc < cols and lives[newr][newc] < live) {
            lives[newr][newc] = live;
            queue.emplace(newr, newc, live);
          }
        }
      }
      step++;
    }
    
    return -1;
  }
};