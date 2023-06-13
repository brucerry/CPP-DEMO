// https://leetcode.com/problems/equal-row-and-column-pairs/

#include <vector>
#include <map>
using namespace std;

// time: O(n^2)
// space: O(n^2)

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> count;
        for (auto& row : grid) {
            count[row]++;
        }

        int n = grid.size(), res = 0;
        vector<int> col;
        for (int c = 0; c < n; c++) {
            col = {};
            for (int r = 0; r < n; r++) {
                col.emplace_back(grid[r][c]);
            }
            if (count.count(col)) {
                res += count[col];
            }
        }

        return res;
    }
};