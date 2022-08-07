// https://leetcode.com/problems/count-vowels-permutation/

#include <array>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int countVowelPermutation(int n) {
    array<int, 5> dp, tmp;
    fill(dp.begin(), dp.end(), 1);
    
    int a = 0, e = 1, i = 2, o = 3, u = 4, mod = 1e9+7;
    for (int cnt = 2; cnt <= n; cnt++) {
      tmp[a] = ((dp[e] + dp[i]) % mod + dp[u]) % mod;
      tmp[e] = (dp[a] + dp[i]) % mod;
      tmp[i] = (dp[e] + dp[o]) % mod;
      tmp[o] = dp[i];
      tmp[u] = (dp[i] + dp[o]) % mod;
      dp = tmp;
    }
    
    int sum = 0;
    for (const int& count : dp)
      sum = (sum + count) % mod;
    
    return sum;
  }
};