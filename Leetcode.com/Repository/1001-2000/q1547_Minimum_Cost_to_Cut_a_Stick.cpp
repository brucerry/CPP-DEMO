// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <vector>
#include <algorithm>
using namespace std;

// k = size of cuts
// time: O(k^3)
// space: O(k^2)
class DP_2D {
public:
  int minCost(int n, vector<int>& cuts) {
    cuts.emplace_back(0);
    cuts.emplace_back(n);
    sort(cuts.begin(), cuts.end());
    
    int k = cuts.size();
    vector<vector<int>> dp (k, vector<int>(k));
    
    for (int l = k - 1; l >= 0; l--) {
      for (int r = l + 1; r < k; r++) {
        for (int i = l + 1; i <= r - 1; i++) {
          int cost = dp[l][r] ? dp[l][r] : INT_MAX;
          dp[l][r] = min(cost, cuts[r] - cuts[l] + dp[l][i] + dp[i][r]);
        }
      }
    }
    
    return dp[0][k-1];
  }
};

// k = size of cuts
// time: O(k^3)
// space: O(k^2)
class TopDownMemo {
public:
  int minCost(int n, vector<int>& cuts) {
    cuts.emplace_back(0);
    cuts.emplace_back(n);
    sort(cuts.begin(), cuts.end());
    
    int k = cuts.size();
    vector<vector<int>> memo (k, vector<int>(k));
    
    return solve(cuts, 0, k - 1, memo);
  }
  
private:
  int solve(vector<int>& cuts, int l, int r, vector<vector<int>>& memo) {
    if (r - l <= 1)
      return 0;
    
    if (memo[l][r])
      return memo[l][r];
    
    int cost = INT_MAX;
    for (int i = l + 1; i <= r - 1; i++) {
      cost = min(cost, cuts[r] - cuts[l] + solve(cuts, l, i, memo) + solve(cuts, i, r, memo));
    }
    
    return memo[l][r] = cost;
  }
};