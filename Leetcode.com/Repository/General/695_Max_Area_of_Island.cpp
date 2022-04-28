// https://leetcode.com/problems/max-area-of-island/

#include <vector>
#include <stack>
using namespace std;

// time: O(r * c)
// space: O(r * c)
class Recursive {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        ans = max(ans, getArea(grid, r, c));
      }
    }
    
    return ans;
  }
  
private:
  int getArea(vector<vector<int>>& grid, int r, int c) {
    if (r < 0 or r == grid.size() or c < 0 or c == grid[0].size() or grid[r][c] == 0)
      return 0;
    
    grid[r][c] = 0;
    
    return 1 +
      getArea(grid, r+1, c) +
      getArea(grid, r-1, c) +
      getArea(grid, r, c+1) +
      getArea(grid, r, c-1);
  }
};

// time: O(r * c)
// space: O(r * c)
class Iterative {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    stack<pair<int, int>> stack;
    
    int ans = 0;
    
    vector<pair<int, int>> dirs { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c]) {
          grid[r][c] = 0;
          stack.emplace(r, c);
          int size = 0;
          
          while (stack.size()) {
            auto [ _r, _c ] = stack.top();
            stack.pop();
            
            size++;
            
            for (const auto& [ dr, dc ] : dirs) {
              int newr = dr + _r;
              int newc = dc + _c;
              
              if (0 <= newr and newr < grid.size() and 0 <= newc and newc < grid[0].size() and grid[newr][newc]) {
                grid[newr][newc] = 0;
                stack.emplace(newr, newc);
              }
            }
          }
          
          ans = max(ans, size);
        }
      }
    }
    
    return ans;
  }
};