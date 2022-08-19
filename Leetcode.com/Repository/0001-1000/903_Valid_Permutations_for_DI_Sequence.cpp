// https://leetcode.com/problems/valid-permutations-for-di-sequence/

#include <string>
using namespace std;

// time: O(n^2)
// space: O(n)
class DP_1D {
public:
  int numPermsDISequence(string& s) {
    int n = s.length(), mod = 1e9 + 7;
    int dp[201] {}, tmp[201];
    
    for (int j = 0; j <= n; j++)
      dp[j] = 1;
    
    for (int i = 0; i < n; i++, memcpy(dp, tmp, sizeof(dp))) {
      if (s[i] == 'I') {
        for (int j = 0, curSum = 0; j < n - i; j++)
          tmp[j] = curSum = (curSum + dp[j]) % mod;
      }
      else {
        for (int j = n - 1 - i, curSum = 0; j >= 0; j--)
          tmp[j] = curSum = (curSum + dp[j+1]) % mod;
      }
    }
    
    return dp[0];
  }
};

// time: O(n^2)
// space: O(n^2)
class DP_2D {
public:
  int numPermsDISequence(string& s) {
    int n = s.length(), mod = 1e9 + 7, dp[201][201] {};
    
    for (int j = 0; j <= n; j++)
      dp[0][j] = 1;
    
    for (int i = 0; i < n; i++) {
      if (s[i] == 'I') {
        for (int j = 0, curSum = 0; j < n - i; j++)
          dp[i+1][j] = curSum = (curSum + dp[i][j]) % mod;
      }
      else {
        for (int j = n - 1 - i, curSum = 0; j >= 0; j--)
          dp[i+1][j] = curSum = (curSum + dp[i][j+1]) % mod;
      }
    }
    
    return dp[n][0];
  }
};