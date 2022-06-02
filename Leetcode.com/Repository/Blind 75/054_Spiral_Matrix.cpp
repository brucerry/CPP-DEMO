// https://leetcode.com/problems/spiral-matrix/

#include <vector>
using namespace std;

// time: O(r * c)
// space: O(1)

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    vector<int> result;
    while (top <= bottom and left <= right) {
      for (int i = left; i <= right; i++)
        result.emplace_back(matrix[top][i]);
      top++;
      
      for (int i = top; i <= bottom; i++)
        result.emplace_back(matrix[i][right]);
      right--;
      
      if (top > bottom or left > right)
        break;
      
      for (int i = right; i >= left; i--)
        result.emplace_back(matrix[bottom][i]);
      bottom--;
      
      for (int i = bottom; i >= top; i--)
        result.emplace_back(matrix[i][left]);
      left++;
    }
    
    return result;
  }
};