// https://leetcode.com/problems/grid-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    
    long long top = 0, bottom = 0;
    for (int i = 1; i < n; i++)
      top += grid[0][i];
    
    long long result = top;
    for (int l = 0, r = 1; r < n; l++, r++) {
      top -= grid[0][r];
      bottom += grid[1][l];
      
      long long secondRobot = max(top, bottom);
      result = min(result, secondRobot);
    }
    
    return result;
  }
};