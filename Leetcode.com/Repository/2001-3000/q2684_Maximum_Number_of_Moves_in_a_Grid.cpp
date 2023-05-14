// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> dp (rows, vector<int>(cols));
        for (int c = cols - 1; c >= 1; c--) {
            for (int r = 0; r < rows; r++) {
                if (r - 1 >= 0 and grid[r-1][c-1] < grid[r][c]) {
                    dp[r-1][c-1] = max(dp[r-1][c-1], 1 + dp[r][c]);
                }
                if (grid[r][c-1] < grid[r][c]) {
                    dp[r][c-1] = max(dp[r][c-1], 1 + dp[r][c]);
                }
                if (r + 1 < rows and grid[r+1][c-1] < grid[r][c]) {
                    dp[r+1][c-1] = max(dp[r+1][c-1], 1 + dp[r][c]);
                }
            }
        }
        
        int res = 0;
        for (int r = 0; r < rows; r++) {
            res = max(res, dp[r][0]);
        }
        
        return res;
    }
};