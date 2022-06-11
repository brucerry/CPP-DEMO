// https://leetcode.com/problems/rotting-oranges/

#include <vector>
#include <queue>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    int fresh = 0;
    queue<pair<int, int>> queue; // r, c
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 1)
          fresh++;
        else if (grid[r][c] == 2)
          queue.emplace(r, c);
      }
    }
    
    vector<pair<int, int>> moves { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
    
    int mins = 0;
    while (queue.size() and fresh) {
      int size = queue.size();
      
      while (size--) {
        auto [ r, c ] = queue.front();
        queue.pop();
        
        for (const auto& [ dr, dc ] : moves) {
          int newr = r + dr;
          int newc = c + dc;
          if (0 <= newr and newr < rows and 0 <= newc and newc < cols and grid[newr][newc] == 1) {
            grid[newr][newc] = 2;
            fresh--;
            queue.emplace(newr, newc);
          }
        }
      }
      mins++;
    }
    
    return fresh ? -1 : mins;
  }
};