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
    
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap; // elev, r, c
    minHeap.emplace(grid[0][0], 0, 0);
    grid[0][0] = -1;
    
    vector<pair<int, int>> moves { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    
    while (minHeap.size()) {
      auto [ elev, r, c ] = minHeap.top();
      minHeap.pop();
      
      if (r == n - 1 and c == n - 1)
        return elev;
      
      for (const auto& [ dr, dc ] : moves) {
        int newr = dr + r;
        int newc = dc + c;
        if (0 <= newr and newr < n and 0 <= newc and newc < n and grid[newr][newc] != -1) {
          minHeap.emplace(max(elev, grid[newr][newc]), newr, newc);
          grid[newr][newc] = -1;
        }
      }
    }
    
    return -1;
  }
};