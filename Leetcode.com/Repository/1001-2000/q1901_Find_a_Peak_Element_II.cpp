// https://leetcode.com/problems/find-a-peak-element-ii/

#include <vector>
using namespace std;

// time: O(r * log(c))
// space: O(1)

class Solution {
public:
  vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size(), l = 0, r = cols - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      int peak_row = 0;
      for (int i = 0; i < rows; i++) {
        if (mat[i][m] > mat[peak_row][m])
          peak_row = i;
      }
      bool right_peak = m + 1 < cols and mat[peak_row][m+1] >= mat[peak_row][m];
      bool left_peak = m - 1 >= 0 and mat[peak_row][m-1] >= mat[peak_row][m];
      if (!right_peak and !left_peak)
        return { peak_row, m };
      if (right_peak)
        l = m + 1;
      else
        r = m - 1;
    }
    return {};
  }
};