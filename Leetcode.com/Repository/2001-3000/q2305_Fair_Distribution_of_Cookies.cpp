// https://leetcode.com/problems/fair-distribution-of-cookies/

#include <vector>
using namespace std;

// time: O(k * 2^n * n)
// space: O(k * 2^n)
class Solution {
public:
  int distributeCookies(vector<int>& cookies, int k) {
    int n = cookies.size();
    
    vector<int> sums (1 << n);
    for (int mask = 0; mask < 1 << n; mask++) {
      for (int i = 0; i < n; i++) {
        sums[mask] += mask & (1 << i) ? cookies[i] : 0;
      }
    }

    vector<vector<int>> dp (k + 1, vector<int>(1 << n, INT_MAX));
    dp[0][0] = 0;

    for (int child = 1; child <= k; child++) {
      for (int mask = 0; mask < 1 << n; mask++) {
        for (int submask = mask; submask; submask = (submask - 1) & mask) {
          dp[child][mask] = min(dp[child][mask], max(sums[submask], dp[child - 1][submask ^ mask]));
        }
      }
    }

    return dp.back().back();
  }
};

// time: O(k * 2^n * n)
// space: O(2^n)
class SpaceOptimized {
public:
  int distributeCookies(vector<int>& cookies, int k) {
    int n = cookies.size();
    
    vector<int> sums (1 << n);
    for (int mask = 0; mask < 1 << n; mask++) {
      for (int i = 0; i < n; i++) {
        sums[mask] += mask & (1 << i) ? cookies[i] : 0;
      }
    }

    vector<int> dp (1 << n, INT_MAX), tmp;
    dp[0] = 0;

    for (int child = 1; child <= k; child++) {
      tmp = dp;
      for (int mask = 0; mask < 1 << n; mask++) {
        for (int submask = mask; submask; submask = (submask - 1) & mask) {
          tmp[mask] = min(tmp[mask], max(sums[submask], dp[submask ^ mask]));
        }
      }
      dp = tmp;
    }

    return dp.back();
  }
};