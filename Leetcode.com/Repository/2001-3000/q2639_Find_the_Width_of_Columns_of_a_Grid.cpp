// https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/

#include <vector>
#include <string>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<int> res (cols);
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                string s = to_string(grid[r][c]);
                res[c] = max(res[c], (int)s.size());
            }
        }
        
        return res;
    }
};