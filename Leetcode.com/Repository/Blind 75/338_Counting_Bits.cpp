// https://leetcode.com/problems/counting-bits/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> dp (n + 1);
    
    int offset = 1;
    for (int num = 1; num <= n; num++) {
      if ((offset << 1) == num)
        offset = num;
      dp[num] = dp[num - offset] + 1;
    }
    
    return dp;
  }
};