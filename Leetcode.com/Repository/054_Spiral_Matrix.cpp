// https://leetcode.com/problems/spiral-matrix/

#include <vector>
using namespace std;


// time: O(r * c)
// space: O(1)
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    vector<int> ans;

    while (left <= right && top <= bottom) {
      // push top-most elements
      for (int c = left; c <= right; c++) ans.push_back(matrix[top][c]);
      top++;

      // push right-most elements
      for (int r = top; r <= bottom; r++) ans.push_back(matrix[r][right]);
      right--;

      // after top & right are modified
      // give it a check
      if (left > right || top > bottom) break;

      // push bottom-most elements
      for (int c = right; c >= left; c--) ans.push_back(matrix[bottom][c]);
      bottom--;

      // push left-most elements
      for (int r = bottom; r >= top; r--) ans.push_back(matrix[r][left]);
      left++;
    }

    return ans;
  }
};

// time: O(r * c)
// space: O(1)
// class Solution {
// private:
//   enum Direction {
//     UP, DOWN, LEFT, RIGHT
//   };

//   void traverse(vector<vector<int>>& matrix, vector<int>& ans, int r, int c, Direction dir, const int* rows, const int* cols) {
//     ans.push_back(matrix[r][c]);
//     matrix[r][c] = INT_MAX;

//     switch (dir) {
//       case UP:
//         if (r-1 >= 0 && matrix[r-1][c] != INT_MAX) {
//           r--;
//         } else if (c+1 < *cols && matrix[r][c+1] != INT_MAX) {
//           c++;
//           dir = RIGHT;
//         } else return;
//         break;

//       case DOWN:
//         if (r+1 < *rows && matrix[r+1][c] != INT_MAX) {
//           r++;
//         } else if (c-1 >= 0 && matrix[r][c-1] != INT_MAX) {
//           c--;
//           dir = LEFT;
//         } else return;
//         break;

//       case LEFT:
//         if (c-1 >= 0 && matrix[r][c-1] != INT_MAX) {
//           c--;
//         } else if (r-1 >= 0 && matrix[r-1][c] != INT_MAX) {
//           r--;
//           dir = UP;
//         } else return;
//         break;

//       case RIGHT:
//         if (c+1 < *cols && matrix[r][c+1] != INT_MAX) {
//           c++;
//         } else if (r+1 < *rows && matrix[r+1][c] != INT_MAX) {
//           r++;
//           dir = DOWN;
//         } else return;
//         break;
//     }

//     traverse(matrix, ans, r, c, dir, rows, cols);
//   }

// public:
//   vector<int> spiralOrder(vector<vector<int>>& matrix) {
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     vector<int> ans;
//     traverse(matrix, ans, 0, 0, RIGHT, &rows, &cols);
//     return ans;
//   }
// };