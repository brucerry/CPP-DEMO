// https://leetcode.com/problems/shortest-bridge/

#include <vector>
#include <queue>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();
    
    vector<vector<char>> visited (n, vector<char>(n));
    
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c]) {
          exploreIsland(grid, n, r, c, visited); // dfs
          return exploreBridge(grid, n, visited); // bfs
        }
      }
    }
    
    return -1;
  }
  
private:
  void exploreIsland(vector<vector<int>>& grid, int n, int r, int c, vector<vector<char>>& visited) {
    if (r < 0 or r >= n or c < 0 or c >= n or grid[r][c] == 0 or visited[r][c])
      return;
    
    visited[r][c] = 1;
    
    exploreIsland(grid, n, r+1, c, visited);
    exploreIsland(grid, n, r-1, c, visited);
    exploreIsland(grid, n, r, c+1, visited);
    exploreIsland(grid, n, r, c-1, visited);
  }
  
  int exploreBridge(vector<vector<int>>& grid, int n, vector<vector<char>>& visited) {
    queue<pair<int, int>> queue; // r, c
    
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (visited[r][c])
          queue.emplace(r, c);
      }
    }
    
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
    
    int ans = 0;
    
    while (queue.size()) {
      int size = queue.size();
      
      while (size--) {
        auto [ r, c ] = queue.front();
        queue.pop();

        for (const auto& [ dr, dc ] : moves) {
          int newr = dr + r;
          int newc = dc + c;
          if (0 <= newr and newr < n and 0 <= newc and newc < n and visited[newr][newc] == 0) {
            if (grid[newr][newc])
              return ans;
            visited[newr][newc] = 1;
            queue.emplace(newr, newc);
          }
        }
      }
      
      ans++;
    }
    
    return ans;
  }
};