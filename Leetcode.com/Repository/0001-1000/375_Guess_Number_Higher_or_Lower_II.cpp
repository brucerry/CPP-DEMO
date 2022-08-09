// https://leetcode.com/problems/guess-number-higher-or-lower-ii/

// time: O(n^3)
// space: O(n^2)

class Solution {
public:
  int getMoneyAmount(int n) {
    int memo[201][201] {};
    return solve(memo, 1, n);
  }
  
private:
  int solve(int (*memo)[201], int l, int r) {
    if (l >= r)
      return 0;
    
    if (memo[l][r])
      return memo[l][r];
    
    int result = INT_MAX;
    for (int i = l; i <= r; i++) {
      result = min(result, i + max(solve(memo, l, i - 1), solve(memo, i + 1, r)));
    }
    
    return memo[l][r] = result;
  }
};