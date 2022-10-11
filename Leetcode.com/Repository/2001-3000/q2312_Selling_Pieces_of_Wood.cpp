// https://leetcode.com/problems/selling-pieces-of-wood/

#include <vector>
using namespace std;

// p = size of prices
// time: O(p + r * c * max(r, c))
// space: O(r * c)

class Solution {
public:
  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    long dp[201][201] {};
    for (const auto& price : prices) {
      int h = price[0], w = price[1], p = price[2];
      dp[h][w] = p;
    }

    for (int r = 1; r <= m; r++) {
      for (int c = 1; c <= n; c++) {
        for (int h = 1; h <= r / 2; h++) {
          dp[r][c] = max(dp[r][c], dp[r-h][c] + dp[h][c]);
        }
        for (int w = 1; w <= c / 2; w++) {
          dp[r][c] = max(dp[r][c], dp[r][c-w] + dp[r][w]);
        }
      }
    }

    return dp[m][n];
  }
};