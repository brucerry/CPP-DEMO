// https://leetcode.com/problems/longest-common-subsequence/

#include <string>
#include <vector>
using namespace std;

// m = len of text1
// n = len of text2
// time: O(m * n)
// space: O(n)

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();
    vector<int> dp (n + 1, 0);
    
    for (int r = m - 1; r >= 0; r--) {
      int prev = 0;
      for (int c = n - 1; c >= 0; c--) {
        int tmp = dp[c];

        if (text1[r] == text2[c])
          dp[c] = prev + 1;
        else
          dp[c] = max(dp[c], dp[c+1]);
          
        prev = tmp;
      }
    }
    
    return dp[0];
  }
};