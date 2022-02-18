/*
  https://leetcode.com/problems/swim-in-rising-water/
*/

#include <iostream>
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

int main() {
  Solution sol;

  vector<vector<int>> set1 = {{0,2},{1,3}};
  vector<vector<int>> set2 = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};

  cout << sol.swimInWater(set1) << endl;
  cout << sol.swimInWater(set2) << endl;
}