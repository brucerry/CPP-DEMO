// https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int res = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                res = max(res, dfs(grid, r, c));
            }
        }
        
        return res;
    }
    
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (min(r, c) < 0 or r >= grid.size() or c >= grid[0].size() or grid[r][c] == 0)
            return 0;
        
        int sum = grid[r][c];
        grid[r][c] = 0;
        
        sum += dfs(grid, r+1, c);
        sum += dfs(grid, r-1, c);
        sum += dfs(grid, r, c+1);
        sum += dfs(grid, r, c-1);
        
        return sum;
    }
};