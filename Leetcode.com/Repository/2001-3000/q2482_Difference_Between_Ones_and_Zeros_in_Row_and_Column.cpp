// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r + c)

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> row (2, vector<int>(rows));
        vector<vector<int>> col (2, vector<int>(cols));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                row[grid[r][c]][r]++;
                col[grid[r][c]][c]++;
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                grid[r][c] = row[1][r] + col[1][c] - row[0][r] - col[0][c];
            }
        }
        return grid;
    }
};