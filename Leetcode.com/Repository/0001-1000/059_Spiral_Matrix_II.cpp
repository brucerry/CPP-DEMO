// https://leetcode.com/problems/spiral-matrix-ii/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result (n, vector<int>(n));
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int count = 1;

    while (top <= bottom and left <= right) {
      for (int c = left; c <= right; c++) {
        result[top][c] = count++;
      }
      top++;

      for (int r = top; r <= bottom; r++) {
        result[r][right] = count++;
      }
      right--;

      if (top > bottom or left > right)
        break;

      for (int c = right; c >= left; c--) {
        result[bottom][c] = count++;
      }
      bottom--;

      for (int r = bottom; r >= top; r--) {
        result[r][left] = count++;
      }
      left++;
    }

    return result;
  }
};