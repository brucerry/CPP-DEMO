// https://leetcode.com/problems/largest-submatrix-with-rearrangements/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r * c * log(c))
// space: O(1)

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int r = 1; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c])
                    matrix[r][c] = matrix[r-1][c] + 1;
            }
        }
        int res = 0;
        for (int r = 0; r < rows; r++) {
            sort(matrix[r].begin(), matrix[r].end());
            for (int c = 0; c < cols; c++) {
                res = max(res, matrix[r][c] * (cols - c));
            }
        }
        return res;
    }
};