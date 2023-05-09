// https://leetcode.com/problems/rotate-image/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        for (int r = 0; r < n; r++) {
            for (int c = r; c < n; c++) {
                swap(matrix[r][c], matrix[c][r]);
            }
        }
    }
};