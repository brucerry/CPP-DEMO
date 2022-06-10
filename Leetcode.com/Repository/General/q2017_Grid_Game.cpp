// https://leetcode.com/problems/grid-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    int cols = grid[0].size();
    
    long long top = 0, bottom = 0;
    for (int c = 1; c < cols; c++)
      top += grid[0][c];
    
    long long point = top;
    for (int l = 0, r = 1; r < cols; l++, r++) {
      top -= grid[0][r];
      bottom += grid[1][l];
      long long get = max(top, bottom);
      point = min(point, get);
    }
    
    return point;
  }
};