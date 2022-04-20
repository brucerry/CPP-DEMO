// https://leetcode.com/problems/regular-expression-matching/

#include <string>
#include <vector>
using namespace std;

// time: O(s * p)
// space: O(s * p)

class TopDownMemo {
public:
  bool isMatch(string s, string p) {
    vector<vector<char>> memo (s.length() + 1, vector<char>(p.length() + 1, -1));
    return solve(s, p, 0, 0, memo);
  }
  
private:
  bool solve(string& s, string& p, int i, int j, vector<vector<char>>& memo) {
    if (j == p.length())
      return i == s.length();
    
    if (memo[i][j] != -1)
      return memo[i][j];
    
    bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');
    
    if (j + 1 < p.length() && p[j + 1] == '*')
      return memo[i][j] = solve(s, p, i, j + 2, memo) || (match && solve(s, p, i + 1, j, memo));
  
    return memo[i][j] = match && solve(s, p, i + 1, j + 1, memo);
  }
};

class BottomUpDP {
public:
  bool isMatch(string s, string p) {
    vector<vector<char>> dp (s.length() + 1, vector<char>(p.length() + 1, 0));
    dp.back().back() = 1;
    
    for (int i = s.length(); i >= 0; i--) {
      for (int j = p.length() - 1; j >= 0; j--) {
        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');
        
        if (j + 1 < p.length() && p[j + 1] == '*')
          dp[i][j] = (match && dp[i + 1][j]) || dp[i][j + 2];
        else
          dp[i][j] = match && dp[i + 1][j + 1];
      }
    }
    
    return dp[0][0];
  }
};