// https://leetcode.com/problems/01-matrix/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int inf = rows + cols;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (mat[r][c]) {
                    int left = c - 1 >= 0 ? mat[r][c-1] : inf;
                    int up = r - 1 >= 0 ? mat[r-1][c] : inf;
                    mat[r][c] = min(left, up) + 1;
                }
            }
        }

        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {
                if (mat[r][c]) {
                    int right = c + 1 < cols ? mat[r][c+1] : inf;
                    int down = r + 1 < rows ? mat[r+1][c] : inf;
                    mat[r][c] = min(mat[r][c], min(right, down) + 1);
                }
            }
        }

        return mat;
    }
};