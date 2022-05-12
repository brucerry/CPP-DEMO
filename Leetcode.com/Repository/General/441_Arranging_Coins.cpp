// https://leetcode.com/problems/arranging-coins/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int arrangeCoins(int n) {
    int l = 1, r = n;
    int rows = 0;
    
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      long coins = m / 2.0 * (m + 1);
      
      if (coins > n)
        r = m - 1;
      else {
        l = m + 1;
        rows = max(rows, m);
      }
    }
    
    return rows;
  }
};