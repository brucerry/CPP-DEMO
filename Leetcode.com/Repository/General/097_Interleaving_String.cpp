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
    int m = s1.length(), n = s2.length();
    
    if (m + n != s3.length())
      return false;
    
    vector<char> dp (n + 1);
    dp.back() = 1;
    
    for (int i = m; i >= 0; i--) {
      for (int j = n; j >= 0; j--) {
        if (i < m or j < n)
          dp[j] = (i < m and s1[i] == s3[i + j] and dp[j]) or (j < n and s2[j] == s3[i + j] and dp[j + 1]);
      }
    }
    
    return dp[0];
  }
};