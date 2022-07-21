// https://leetcode.com/problems/unique-binary-search-trees/

#include <vector>
using namespace std;

// time: O(n^2)
// space: O(n)

class Solution {
public:
  int numTrees(int n) {
    vector<int> dp (n + 1);
    dp[0] = 1;
    
    for (int each_n = 1; each_n <= n; each_n++) {      
      for (int root = 1; root <= each_n; root++) {
        int lCount = root - 1;
        int rCount = each_n - root;
        dp[each_n] += dp[lCount] * dp[rCount];
      }
    }
    
    return dp[n];
  }
};