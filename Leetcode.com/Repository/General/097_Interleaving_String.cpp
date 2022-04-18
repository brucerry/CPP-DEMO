// https://leetcode.com/problems/interleaving-string/

#include <string>
#include <vector>
using namespace std;

// m = len of s1
// n = len of s2
// time: O(m * n)
// space: O(n)

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.length();
    int n = s2.length();
    
    if (m + n != s3.length())
      return false;
    
    vector<char> dp (n + 1);
    
    for (int r = m; r >= 0; r--) {
      for (int c = n; c >= 0; c--) {
        if (r == m && c == n)
          dp[c] = 1;
        else
          dp[c] = (r < m && s1[r] == s3[r + c] && dp[c]) || (c < n && s2[c] == s3[r + c] && dp[c + 1]);
      }
    }
    
    return dp[0];
  }
};