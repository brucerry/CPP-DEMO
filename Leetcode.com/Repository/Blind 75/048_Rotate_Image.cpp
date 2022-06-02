// https://leetcode.com/problems/rotate-image/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    int i = 0, j = n - 1;
    while (i < j) {
      matrix[i].swap(matrix[j]);
      i++;
      j--;
    }
    
    for (int r = 0; r < n; r++) {
      for (int c = r; c < n; c++) {
        swap(matrix[r][c], matrix[c][r]);
      }
    }
  }
};