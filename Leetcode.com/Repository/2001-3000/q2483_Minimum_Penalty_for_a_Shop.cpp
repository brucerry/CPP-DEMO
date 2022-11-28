// https://leetcode.com/problems/minimum-penalty-for-a-shop/

#include <string>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int bestClosingTime(string customers) {
    int n = customers.size();

    int dp[100001] {};
    for (int i = 0; i < n; i++) {
      if (customers[i] == 'N')
        dp[n]++;
    }

    for (int i = n - 1; i >= 0; i--) {
      if (customers[i] == 'Y')
        dp[i] = dp[i+1] + 1;
      else
        dp[i] = dp[i+1] - 1;
    }
    
    int res = n, cost = n;
    for (int i = 0; i <= n; i++) {
      if (dp[i] < cost) {
        cost = dp[i];
        res = i;
      }
    }
    
    return res;
  }
};