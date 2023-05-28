// https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(r * c * max(r, c))
// space: O(max(r, c))

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> res (rows, vector<int>(cols));
        unordered_set<int> topleft, bottomright;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                topleft = bottomright = {};
                for (int r1 = r - 1, c1 = c - 1; min(r1, c1) >= 0; r1--, c1--) {
                    topleft.emplace(grid[r1][c1]);
                }
                for (int r1 = r + 1, c1 = c + 1; r1 < rows and c1 < cols; r1++, c1++) {
                    bottomright.emplace(grid[r1][c1]);
                }
                res[r][c] = abs(int(topleft.size() - bottomright.size()));
            }
        }
        
        return res;
    }
};