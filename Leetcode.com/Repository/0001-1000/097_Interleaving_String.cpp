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
  bool isInterleave(string& s1, string& s2, string& s3) {
    int rows = s1.length();
    int cols = s2.length();
    
    if (rows + cols != s3.length())
      return false;
    
    vector<char> dp (cols + 1);
    dp.back() = 1;
    
    for (int r = rows; r >= 0; r--) {
      for (int c = cols; c >= 0; c--) {
        if (r < rows or c < cols)
          dp[c] = (r < rows and s1[r] == s3[r+c] and dp[c]) or (c < cols and s2[c] == s3[r+c] and dp[c+1]);
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
    int rows = s1.length();
    int cols = s2.length();
    
    if (rows + cols != s3.length())
      return false;
    
    vector<vector<char>> dp (rows + 1, vector<char>(cols + 1));
    dp.back().back() = 1;
    
    for (int r = rows; r >= 0; r--) {
      for (int c = cols; c >= 0; c--) {
        if (r < rows or c < cols)
          dp[r][c] |= (r < rows and s1[r] == s3[r+c] and dp[r+1][c]) or (c < cols and s2[c] == s3[r+c] and dp[r][c+1]);
      }
    }
    
    return dp[0][0];
  }
};