// https://leetcode.com/problems/minimum-falling-path-sum/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int r = 1; r < n; r++) {
      for (int c = 0; c < n; c++) {
        int left = 0 <= c - 1 ? matrix[r-1][c-1] : INT_MAX;
        int mid = matrix[r-1][c];
        int right = c + 1 < n ? matrix[r-1][c+1] : INT_MAX;
        matrix[r][c] += min({ left, mid ,right });
      }
    }
    return *min_element(matrix.back().begin(), matrix.back().end());
  }
};