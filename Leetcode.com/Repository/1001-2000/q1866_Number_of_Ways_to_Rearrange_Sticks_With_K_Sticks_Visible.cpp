// https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/

#include <vector>
using namespace std;

// time: O(n * k)
// space: O(k)
class TopDownDP_1D {
public:
  int rearrangeSticks(int n, int k) {
    vector<int> dp (k + 1);
    dp[1] = 1;
    
    for (int r = 2; r <= n; r++) {
      for (int c = k; c >= 1; c--) {
        if (r >= c) {
          dp[c] = (dp[c-1] + (long)(r-1) * dp[c]) % 1000000007;
        }
      }
    }
    
    return dp[k];
  }
};

// time: O(n * k)
// space: O(n * k)
class TopDownDP_2D {
public:
  int rearrangeSticks(int n, int k) {
    vector<vector<int>> dp (n + 1, vector<int>(k + 1));
    dp[1][1] = 1;
    
    for (int r = 2; r <= n; r++) {
      for (int c = 1; c <= k; c++) {
        if (r >= c) {
          dp[r][c] = (dp[r-1][c-1] + (long)(r-1) * dp[r-1][c]) % 1000000007;
        }
      }
    }
    
    return dp[n][k];
  }
};

// time: O(n * k)
// space: O(n * k)
class TopDownMemo {
public:
  int rearrangeSticks(int n, int k) {
    vector<vector<long>> memo (n + 1, vector<long>(k + 1, -1));
    return solve(n, k, memo);
  }
  
private:
  long solve(int n, int k, vector<vector<long>>& memo) {
    if (!n or !k or n < k)
      return 0;
    
    if (n == k)
      return 1;
    
    if (memo[n][k] != -1)
      return memo[n][k];
    
    return memo[n][k] = (solve(n - 1, k - 1, memo) + (n - 1) * solve(n - 1, k, memo)) % 1000000007;
  }
};