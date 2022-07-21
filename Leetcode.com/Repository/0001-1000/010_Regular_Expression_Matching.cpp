// https://leetcode.com/problems/regular-expression-matching/

#include <string>
#include <vector>
using namespace std;

// time: O(s * p)
// space: O(s * p)
class TopDownMemo {
public:
  bool isMatch(string& s, string& p) {
    int m = s.length();
    int n = p.length();
    
    vector<vector<char>> memo (m + 1, vector<char>(n + 1, -1));
    return solve(s, p, 0, 0, memo);
  }
  
private:
  bool solve(string& s, string& p, int i, int j, vector<vector<char>>& memo) {
    if (j == p.length())
      return i == s.length();
    
    if (memo[i][j] != -1)
      return memo[i][j];
    
    bool match = i < s.length() and (s[i] == p[j] or p[j] == '.');
    
    if (j + 1 < p.length() and p[j+1] == '*')
      return memo[i][j] = (match and solve(s, p, i+1, j, memo)) or solve(s, p, i, j+2, memo);
    
    return memo[i][j] = match and solve(s, p, i+1, j+1, memo);
  }
};

// time: O(s * p)
// space: O(s * p)
class BottomUpDP_2D {
public:
  bool isMatch(string& s, string& p) {
    int m = s.length();
    int n = p.length();
    
    vector<vector<char>> dp (m + 1, vector<char>(n + 1));
    dp.back().back() = 1;
    
    for (int i = m; i >= 0; i--) {
      for (int j = n - 1; j >= 0; j--) {
        bool match = i < m and (s[i] == p[j] or p[j] == '.');
        if (j + 1 < n and p[j+1] == '*')
          dp[i][j] = (match and dp[i+1][j]) or dp[i][j+2];
        else
          dp[i][j] = match and dp[i+1][j+1];
      }
    }
    
    return dp[0][0];
  }
};

// time: O(s * p)
// space: O(p)
class BottomUpDP_1D {
public:
  bool isMatch(string& s, string& p) {
    int m = s.length();
    int n = p.length();
    
    vector<char> dp (n + 1);
    
    for (int i = m; i >= 0; i--) {
      int prev = i == m - 1 ? 1 : 0;
      dp.back() = i == m ? 1 : 0;
      
      for (int j = n - 1; j >= 0; j--) {
        int tmp = dp[j];
        
        bool match = i < m and (s[i] == p[j] or p[j] == '.');
        if (j + 1 < n and p[j+1] == '*')
          dp[j] = (match and dp[j]) or dp[j+2];
        else
          dp[j] = match and prev;
        
        prev = tmp;
      }
    }
    
    return dp[0];
  }
};