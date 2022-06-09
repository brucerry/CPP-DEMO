// https://leetcode.com/problems/max-area-of-island/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)
class DFS {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    int area = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        area = max(area, exploreArea(grid, r, c));
      }
    }
    
    return area;
  }
  
private:
  int exploreArea(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == 0)
      return 0;
    
    grid[r][c] = 0;
    
    return 1 +
      exploreArea(grid, r+1, c) +
      exploreArea(grid, r-1, c) +
      exploreArea(grid, r, c+1) +
      exploreArea(grid, r, c-1);
  }
};

// time: O(r * c)
// space: O(r * c)
class BFS {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<pair<int, int>> buffer; // r, c
    int maxArea = 0;
    
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c]) {
          int area = 0;
          grid[r][c] = 0;
          buffer.emplace_back(r, c);
          
          while (buffer.size()) {
            auto [ _r, _c ] = buffer.back();
            buffer.pop_back();
            
            area++;
            
            for (const auto& [ dr, dc ] : moves) {
              int newr = _r + dr;
              int newc = _c + dc;
              if (0 <= newr and newr < rows and 0 <= newc and newc < cols and grid[newr][newc]) {
                grid[newr][newc] = 0;
                buffer.emplace_back(newr, newc);
              }
            }
          }
          
          maxArea = max(maxArea, area);
        }
      }
    }
    
    return maxArea;
  }
};