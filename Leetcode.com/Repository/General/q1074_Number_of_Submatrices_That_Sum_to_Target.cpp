// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

#include <vector>
#include <unordered_map>
using namespace std;

// time: O(r * c^2)
// space: O(r)

class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    for (int r = 0; r < rows; r++) {
      for (int c = 1; c < cols; c++) {
        matrix[r][c] += matrix[r][c-1];
      }
    }
    
    unordered_map<int, int> prefixCount; // prefix sum, count
    int submatrix = 0;
    for (int cl = 0; cl < cols; cl++) {
      for (int cr = cl; cr < cols; cr++) {
        prefixCount = { { 0, 1 } };
        int curSum = 0;
        for (int r = 0; r < rows; r++) {
          curSum += matrix[r][cr] - (cl ? matrix[r][cl-1] : 0);
          submatrix += prefixCount.count(curSum - target) ? prefixCount[curSum - target] : 0;
          prefixCount[curSum]++;
        }
      }
    }
    
    return submatrix;
  }
};