// https://leetcode.com/problems/reshape-the-matrix/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int rows = mat.size(), cols = mat[0].size();
    if (rows * cols != r * c)
      return mat;

    vector<vector<int>> result (r, vector<int>(c));
    for (int i = 0; i < r * c; i++) {
      result[i/c][i%c] = mat[i/cols][i%cols];
    }
    return result;
  }
};