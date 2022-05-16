// https://leetcode.com/problems/distinct-subsequences/

#include <string>
#include <vector>
using namespace std;

// time: O(s * t)
// space: O(t)

class Solution {
public:
  int numDistinct(string& s, string& t) {
    int rows = s.length();
    int cols = t.length();
    
    vector<unsigned int> dp (cols + 1);
    dp.back() = 1;
    
    for (int r = rows - 1; r >= 0; r--) {
      for (int c = 0; c < cols; c++) {
        if (s[r] == t[c])
          dp[c] += dp[c+1];
        if (r == 0 and c == 0)
          break;
      }
    }
    
    return dp[0];
  }
};