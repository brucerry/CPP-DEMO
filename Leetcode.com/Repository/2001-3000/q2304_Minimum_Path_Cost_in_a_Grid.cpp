// https://leetcode.com/problems/minimum-path-cost-in-a-grid/

#include <vector>
#include <queue>
#include <array>
using namespace std;

// time: O(r * c * c)
// space: O(c)
class TopDownDP_1D {
public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> dp = grid[0];
    
    for (int r = 1; r < rows; r++) {
      vector<int> tmp (cols, INT_MAX);
      for (int c = 0; c < cols; c++) {
        for (int topc = 0; topc < cols; topc++) {
          int prevVal = grid[r-1][topc];
          tmp[c] = min(tmp[c], dp[topc] + grid[r][c] + moveCost[prevVal][c]);
        }
      }
      dp = tmp;
    }
    
    return *min_element(dp.begin(), dp.end());
  }
};

// time: O(r * c * c * log(r * c))
// space: O(r * c)
class MinHeap {
public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    vector<vector<int>> minCost (rows, vector<int>(cols, INT_MAX));
    
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> minHeap; // cost, val, rowIndex
    for (int c = 0; c < cols; c++) {
      minHeap.push({ grid[0][c], grid[0][c], 0 });
    }
    
    while (minHeap.size()) {
      auto [ cost, val, r ] = minHeap.top();
      minHeap.pop();
      
      if (r == rows - 1)
        return cost;
      
      for (int c = 0; c < moveCost[val].size(); c++) {
        int nextVal = grid[r+1][c];
        int sumCost = cost + nextVal + moveCost[val][c];
        if (sumCost < minCost[r+1][c]) {
          minCost[r+1][c] = sumCost;
          minHeap.push({ sumCost, nextVal, r + 1 });
        }
      }
    }
    
    return -1;
  }
};