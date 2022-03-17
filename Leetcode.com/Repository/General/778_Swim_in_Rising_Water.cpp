/*
  https://leetcode.com/problems/swim-in-rising-water/
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

  vector<vector<int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
  class pair_{
      
      public:
      int time;
      int x;
      int y;
      
      pair_(int time, int x, int y)
      {
          this->time=time;
          this->x=x;
          this->y=y;
      }
  };
  
  struct comp{ //Construction of Min Heap
      
      bool operator()(pair_ &a, pair_ &b)
      {
          return a.time > b.time;
      }
  };
  
  bool isSafe(int x, int y, int n)
  {
      return x>=0 && x<n && y>=0 && y<n;
  }

  int swimInWater(vector<vector<int>>& grid) {
    priority_queue<pair_, vector<pair_>, comp> minHeap;
    int n = grid.size();

    minHeap.push(pair_(grid[0][0], 0, 0)); // { time, r, c }
    
    while (minHeap.size()) {
      int time = minHeap.top().time;
      int x = minHeap.top().x;
      int y = minHeap.top().y;

      grid[x][y] = -1; // visited
      minHeap.pop();

      for (int i = 0; i < moves.size(); i++) {
        int neighborX = x + moves[i][0];
        int neighborY = y + moves[i][1];

        if (isSafe(neighborX, neighborY, n) && grid[neighborX][neighborY] != -1) {
          int neighborTime = max(grid[neighborX][neighborY], time);
          if (neighborX == n-1 && neighborY == n-1) {
            return neighborTime;
          }
          minHeap.push(pair_(neighborTime, neighborX, neighborY));
        }
      }
    }

    return 0;
  }
};