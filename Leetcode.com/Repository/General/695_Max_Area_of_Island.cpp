// https://leetcode.com/problems/max-area-of-island/

#include <vector>
#include <stack>
using namespace std;

// time: O(r * c)
// space: O(r * c)
class Recursive {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        maxArea = max(maxArea, calArea(grid, r, c));
      }
    }
    
    return maxArea;
  }
  
private:
  int calArea(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == 0)
      return 0;
    
    grid[r][c] = 0;
    
    return 1 +
      calArea(grid, r+1, c) +
      calArea(grid, r-1, c) +
      calArea(grid, r, c+1) +
      calArea(grid, r, c-1);
  }
};

// time: O(r * c)
// space: O(r * c)
class Iterative {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    stack<pair<int, int>> stack; // r, c
    int maxArea = 0;
    
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c]) {
          int area = 0;
          grid[r][c] = 0;
          stack.emplace(r, c);
          
          while (stack.size()) {
            auto [ _r, _c ] = stack.top();
            stack.pop();
            
            area++;
            
            for (const auto& [ dr, dc ] : moves) {
              int newr = _r + dr;
              int newc = _c + dc;
              if (0 <= newr and newr < grid.size() and 0 <= newc and newc < grid[0].size() and grid[newr][newc]) {
                grid[newr][newc] = 0;
                stack.emplace(newr, newc);
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