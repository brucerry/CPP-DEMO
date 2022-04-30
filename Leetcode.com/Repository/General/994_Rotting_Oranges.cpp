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
    
    int freshCount = 0;
    
    queue<pair<int, int>> queue;
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] == 1)
          freshCount++;
        else if (grid[r][c] == 2)
          queue.emplace(r, c);
      }
    }
    
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    int mins = 0;
    
    while (queue.size() and freshCount) {
      int size = queue.size();
      
      while (size--) {
        auto [ r, c ] = queue.front();
        queue.pop();
        
        for (const auto& [ dr, dc ] : moves) {
          int newr = dr + r;
          int newc = dc + c;
          if (0 <= newr and newr < rows and 0 <= newc and newc < cols and grid[newr][newc] == 1) {
            freshCount--;
            grid[newr][newc] = 2;
            queue.emplace(newr, newc);
          }
        }
      }
      
      mins++;
    }
    
    return freshCount ? -1 : mins;
  }
};