// https://leetcode.com/problems/diagonal-traverse/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> res;
        int r = 0, c = 0, dir = 1;
        for (int cnt = 0; cnt < rows * cols; cnt++) {
            res.emplace_back(mat[r][c]);
            r -= dir;
            c += dir;
            if (r < 0 or r >= rows or c < 0 or c >= cols) {
                if (r >= rows)
                    c += 2;
                if (c >= cols)
                    r += 2;
                r = max(r, 0);
                r = min(r, rows - 1);
                c = max(c, 0);
                c = min(c, cols - 1);
                dir = -dir;
            }
        }
        return res;
    }
};