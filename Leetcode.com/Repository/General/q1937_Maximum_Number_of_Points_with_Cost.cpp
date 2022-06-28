// https://leetcode.com/problems/maximum-number-of-points-with-cost/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(r * c)
// space: O(c)

class Solution {
public:
  long long maxPoints(vector<vector<int>>& points) {
    int rows = points.size();
    int cols = points[0].size();
    
    vector<long long> dp (points[0].begin(), points[0].end());
    vector<long long> prefix, postfix;
    
    for (int r = 1; r < rows; r++) {
      prefix = postfix = dp;
      
      for (int c = 1; c < cols; c++) {
        prefix[c] = max(prefix[c], prefix[c-1] - 1);
      }
      
      for (int c = cols - 2; c >= 0; c--) {
        postfix[c] = max(postfix[c], postfix[c+1] - 1);
      }
      
      for (int c = 0; c < cols; c++) {
        dp[c] = points[r][c] + max(prefix[c], postfix[c]);
      }
    }
    
    return *max_element(dp.begin(), dp.end());
  }
};