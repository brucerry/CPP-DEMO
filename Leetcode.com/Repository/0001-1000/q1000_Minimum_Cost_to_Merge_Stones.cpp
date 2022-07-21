// https://leetcode.com/problems/minimum-cost-to-merge-stones/

#include <vector>
using namespace std;

// time: O(n^3)
// space: O(n^2)
class DP_2D {
public:
  int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    
    if ((n - 1) % (k - 1))
      return -1;
    
    vector<int> prefixSum (n + 1);
    for (int i = 0; i < n; i++) {
      prefixSum[i+1] = prefixSum[i] + stones[i];
    }
    
    vector<vector<int>> dp (n, vector<int>(n, INT_MAX));
    for (int l = n - 1; l >= 0; l--) {
      for (int r = 0; r < n; r++) {
        if (l == r) {
          dp[l][r] = 0;
          continue;
        }
        for (int i = l; i < r; i += k - 1) {
          dp[l][r] = min(dp[l][r], dp[l][i] + dp[i+1][r]);
        }
        if ((r - l) % (k - 1) == 0)
          dp[l][r] += prefixSum[r + 1] - prefixSum[l];
      }
    }
    
    return dp[0][n-1];
  }
};

// time: O(n^3)
// space: O(n^2)
class TopDownMemo {
public:
  int mergeStones(vector<int>& stones, int k) {
    int n = stones.size();
    
    if ((n - 1) % (k - 1))
      return -1;
    
    vector<int> prefixSum (n + 1);
    for (int i = 0; i < n; i++) {
      prefixSum[i+1] = prefixSum[i] + stones[i];
    }
    
    vector<vector<int>> memo (n, vector<int>(n));
    return solve(k, 0, n - 1, prefixSum, memo);
  }
  
private:
  int solve(int k, int l, int r, vector<int>& prefixSum, vector<vector<int>>& memo) {
    if (l == r)
      return 0;
    
    if (memo[l][r])
      return memo[l][r];
    
    int cost = INT_MAX;
    for (int i = l; i < r; i += k - 1) {
      cost = min(cost, solve(k, l, i, prefixSum, memo) +
                       solve(k, i + 1, r, prefixSum, memo));
    }
    
    if ((r - l) % (k - 1) == 0)
      cost += prefixSum[r + 1] - prefixSum[l];
    
    return memo[l][r] = cost;
  }
};