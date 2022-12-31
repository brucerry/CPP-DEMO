// https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(r * c)

class Solution {
public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> prefix (rows + 1, vector<int>(cols + 1));
    int res = 0;
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        prefix[r+1][c+1] = prefix[r][c+1] + prefix[r+1][c] - prefix[r][c] + mat[r][c];
        if (min(r-res, c-res) >= 0 and prefix[r+1][c+1] - prefix[r-res][c+1] - prefix[r+1][c-res] + prefix[r-res][c-res] <= threshold)
          res++;
      }
    }
    return res;
  }
};