// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include <vector>
#include <queue>
#include <array>
#include <cstring>
using namespace std;

// time: O(r * c * k)
// space: O(r * c * k)

class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int rows = grid.size(), cols = grid[0].size();

    int counts[40][40];
    memset(counts, -1, sizeof(counts));
    counts[0][0] = k;
    
    char moves[] { 0, 1, 0, -1, 0 }; // 4-dir

    queue<array<int, 3>> queue; // r, c, k
    queue.push({ 0, 0, k });

    int steps = 0;
    while (queue.size()) {
      for (int size = queue.size(); size; size--) {
        auto [ r, c, cur_k ] = queue.front();
        queue.pop();
        
        if (r == rows - 1 and c == cols - 1)
          return steps;

        cur_k -= (grid[r][c] == 1);

        for (int i = 0; i < 4; i++) {
          int newr = r + moves[i];
          int newc = c + moves[i+1];
          if (0 <= min(newr, newc) and newr < rows and newc < cols and cur_k > counts[newr][newc]) {
            counts[newr][newc] = cur_k;
            queue.push({ newr, newc, cur_k });
          }
        }
      }
      steps++;
    }

    return -1;
  }
};