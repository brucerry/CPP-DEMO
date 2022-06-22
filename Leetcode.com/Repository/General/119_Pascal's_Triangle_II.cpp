// https://leetcode.com/problems/pascals-triangle-ii/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> dp (rowIndex + 1);
    dp[0] = dp.back() = 1;
    
    for (int r = 0; r < rowIndex; r++) {
      for (int c = rowIndex - 1; c >= 1; c--) {
        dp[c] += dp[c-1];
      }
    }
    
    return dp;
  }
};