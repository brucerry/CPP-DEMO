// https://leetcode.com/problems/interleaving-string/

#include <string>
#include <vector>
using namespace std;

// m = len of s1
// n = len of s2
// time: O(m * n)
// space: O(n)
class DP_1D {
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

// m = len of s1
// n = len of s2
// time: O(m * n)
// space: O(m * n)
class DP_2D {
public:
  bool isInterleave(string& s1, string& s2, string& s3) {
    int m = s1.length();
    int n = s2.length();
    
    if (m + n != s3.length())
      return false;
    
    vector<vector<char>> dp (m + 1, vector<char>(n + 1));
    dp.back().back() = 1;
    
    for (int i = m; i >= 0; i--) {
      for (int j = n; j >= 0; j--) {
        if (i < m or j < n)
          dp[i][j] = (i < m and s1[i] == s3[i+j] and dp[i+1][j]) or (j < n and s2[j] == s3[i+j] and dp[i][j+1]);
      }
    }
    
    return dp[0][0];
  }
};