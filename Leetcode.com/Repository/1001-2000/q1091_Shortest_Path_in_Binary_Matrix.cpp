// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <vector>
#include <queue>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    queue<pair<int, int>> queue; // r, c
    if (grid[0][0] == 0)
      queue.emplace(0, 0);
    grid[0][0] = 1;

    char moves[] { 0, 1, 1, -1, -1, 1, 0, -1, 0 }; // 8-directionally
    
    int dist = 1;
    while (queue.size()) {
      for (int size = queue.size(); size; size--) {
        auto [ r, c] = queue.front();
        queue.pop();

        if (r == n - 1 and c == n - 1)
          return dist;
        
        for (int i = 0; i < 8; i++) {
          int newr = r + moves[i], newc = c + moves[i+1];
          if (min(newr, newc) >= 0 and newr < n and newc < n and grid[newr][newc] == 0) {
            grid[newr][newc] = 1;
            queue.emplace(newr, newc);
          }
        }
      }
      dist++;
    }

    return -1;
  }
};