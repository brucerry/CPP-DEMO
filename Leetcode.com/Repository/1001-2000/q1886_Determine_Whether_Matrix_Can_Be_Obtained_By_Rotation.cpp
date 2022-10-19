// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    int n = mat.size(), mask = 0b1111;
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        if (mat[r][c] != target[r][c]) // rotate 0
          mask &= ~(1 << 0);
        if (mat[r][c] != target[n-1-c][r]) // rotate 1
          mask &= ~(1 << 1);
        if (mat[r][c] != target[n-1-r][n-1-c]) // rotate 2
          mask &= ~(1 << 2);
        if (mat[r][c] != target[c][n-1-r]) // rotate 3
          mask &= ~(1 << 3);
      }
    }
    return mask;
  }
};