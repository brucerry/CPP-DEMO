// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
    int mod = 1e9 + 7;

    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> memo (rows, vector<int>(cols));
        int res = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                res = (res + solve(grid, memo, r, c, 0)) % mod;
            }
        }
        return res;
    }

private:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& memo, int r, int c, int prev) {
        if (min(r, c) < 0 or r == grid.size() or c == grid[0].size() or grid[r][c] <= prev)
            return 0;
        
        int& res = memo[r][c];
        if (res)
            return res;
        
        res = 1;
        res = (res + solve(grid, memo, r+1, c, grid[r][c])) % mod;
        res = (res + solve(grid, memo, r-1, c, grid[r][c])) % mod;
        res = (res + solve(grid, memo, r, c+1, grid[r][c])) % mod;
        res = (res + solve(grid, memo, r, c-1, grid[r][c])) % mod;

        return res;
    }
};