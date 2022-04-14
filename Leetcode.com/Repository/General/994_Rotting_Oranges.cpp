// https://leetcode.com/problems/rotting-oranges/

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> queue;
    int freshCount = 0;
    
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c] == 1) {
          freshCount++;
        }
        else if (grid[r][c] == 2) {
          queue.emplace(r, c);
        }
      }
    }
    
    int ans = 0;
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    while (queue.size() && freshCount) {
      int len = queue.size();
      
      while (len--) {
        auto [ r, c ] = queue.front();
        queue.pop();
      
        for (const auto& [ dr, dc ] : moves) {
          int newr = r + dr;
          int newc = c + dc;
          if (0 <= newr && newr < grid.size() && 0 <= newc && newc < grid[0].size() && grid[newr][newc] == 1) {
            grid[newr][newc] = 2;
            queue.emplace(newr, newc);
            freshCount--;
          }
        }
      }
      
      ans++;
    }
    
    return freshCount ? -1 : ans;
  }
};