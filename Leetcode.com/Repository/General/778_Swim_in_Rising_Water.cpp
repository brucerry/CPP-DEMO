// https://leetcode.com/problems/swim-in-rising-water/

#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// time: O(n^2 * log(n))
// space: O(n^2)

class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
    minHeap.emplace(grid[0][0], 0, 0);
    
    int ans = 0;
    
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    while (minHeap.size()) {
      auto [ elev, r, c ] = minHeap.top();
      minHeap.pop();
      
      ans = max(ans, elev);
      
      if (r == n - 1 && c == n - 1)
        break;
      
      for (const auto& [ dr, dc ] : moves) {
        int newr = r + dr;
        int newc = c + dc;
        if (0 <= newr && newr < n && 0 <= newc && newc < n && grid[newr][newc] != -1) {
          minHeap.emplace(grid[newr][newc], newr, newc);
          grid[newr][newc] = -1; // visited
        }
      }
    }
    
    return ans;
  }
};