// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int countUnguarded(int rows, int cols, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<char>> grid (rows, vector<char>(cols));
    for (const auto& wall : walls) {
      int r = wall[0], c = wall[1];
      grid[r][c] = 0b1111;
    }
    
    char moves[] { 0, 1, 0, -1, 0 };
    int not_guarded = rows * cols - walls.size();
    for (const auto& guard : guards) {
      for (int i = 0; i < 4; i++) {
        for (int r = guard[0], c = guard[1]; 0 <= r and r < rows and 0 <= c and c < cols and (grid[r][c] & (1 << i)) == 0; r += moves[i], c += moves[i+1]) {
          not_guarded -= grid[r][c] == 0;
          grid[r][c] |= 1 << i;
        }
      }
    }
    
    return not_guarded;
  }
};