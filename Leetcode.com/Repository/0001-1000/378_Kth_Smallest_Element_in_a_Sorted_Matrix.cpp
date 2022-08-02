// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include <vector>
using namespace std;

// time: O(n * log(max(matrix)))
// space: O(1)

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    
    int l = matrix[0][0], r = matrix[n-1][n-1];
    while (l < r) {
      int m = l + ((r - l) >> 1);
      int largerCount = 0;
      for (int r = 0, c = n - 1; r < n; r++) {
        while (c >= 0 and matrix[r][c] > m)
          c--;
        largerCount += c + 1;
      }
      if (largerCount >= k)
        r = m;
      else
        l = m + 1;
    }
    
    return r;
  }
};