// https://leetcode.com/problems/number-of-beautiful-partitions/

#include <string>
#include <cstring>
using namespace std;

// time: O(n * k)
// space: O(n * k)

class Solution {
#define MOD 1000000007

public:
  int beautifulPartitions(string s, int k, int minLength) {
    int dp[2][1001][1001];
    memset(dp, -1, sizeof(dp));
    return solve(s, k, minLength, dp, 0, true);
  }

private:
  int solve(string& s, int k, int minLength, int (*dp)[1001][1001], int i, bool isStart) {
    if (i == s.size())
      return k == 0;
    
    if (k == 0 or i > s.size() or (isStart and !isPrime(s[i])))
      return 0;

    int& res = dp[isStart][i][k];
    if (res != -1)
      return res;
    
    res = 0;
    if (isPrime(s[i])) {
      if (isStart)
        res = solve(s, k, minLength, dp, i + minLength - 1, false);
      else
        res = solve(s, k, minLength, dp, i + 1, false);
    }
    else {
      int end = solve(s, k - 1, minLength, dp, i + 1, true);
      int cont = solve(s, k, minLength, dp, i + 1, false);
      res = ((res + end) % MOD + cont) % MOD;
    }

    return res;
  }

  bool isPrime(char c) {
    return c == '2' or c == '3' or c == '5' or c == '7';
  }
};