// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

// time: O(n * k)
// space: O(n * k)

class Solution {
public:
  int numberOfWays(int startPos, int endPos, int k) {
    int memo[1000][1001] {};
    memset(memo, -1, sizeof(memo));
    return solve(abs(startPos - endPos), k, memo);
  }
  
private:
  int solve(int distance, int k, int (*memo)[1001]) {
    if (distance >= k)
      return distance == k;
    
    if (memo[distance][k] != -1)
      return memo[distance][k];
    
    int ways = 0, mod = 1e9 + 7;
    ways = (ways + solve(distance + 1, k - 1, memo)) % mod;
    ways = (ways + solve(distance + (distance ? -1 : 1), k - 1, memo)) % mod;
    
    return memo[distance][k] = ways;
  }
};