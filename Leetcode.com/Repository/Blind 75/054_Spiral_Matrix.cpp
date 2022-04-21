// https://leetcode.com/problems/spiral-matrix/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    
    int left = 0, right = matrix[0].size() - 1;
    int top = 0, bottom = matrix.size() - 1;

    while (left <= right && top <= bottom) {
      // push top-most elements
      for (int c = left; c <= right; c++)
        ans.emplace_back(matrix[top][c]);
      top++;

      // push right-most elements
      for (int r = top; r <= bottom; r++)
        ans.emplace_back(matrix[r][right]);
      right--;

      // after top & right are modified
      // give it a check
      if (left > right || top > bottom) break;

      // push bottom-most elements
      for (int c = right; c >= left; c--)
        ans.emplace_back(matrix[bottom][c]);
      bottom--;

      // push left-most elements
      for (int r = bottom; r >= top; r--)
        ans.emplace_back(matrix[r][left]);
      left++;
    }

    return ans;
  }
};