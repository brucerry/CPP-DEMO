// https://leetcode.com/problems/find-a-good-subset-of-the-matrix/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(r * 2^c)
// space: O(2^c)

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        unordered_map<int, int> index; // mask, index
        for (int r = 0; r < rows; r++) {
            int mask = 0;
            for (int c = 0; c < cols; c++) {
                mask |= (grid[r][c] << c);
            }

            if (mask == 0)
                return { r };

            for (auto& [ m, i ] : index) {
                if ((mask & m) == 0)
                    return { i, r };
            }
            index[mask] = r;
        }
        return {};
    }
};