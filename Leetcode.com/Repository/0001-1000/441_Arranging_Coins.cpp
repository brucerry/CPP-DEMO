// https://leetcode.com/problems/arranging-coins/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int arrangeCoins(int n) {
    int row = 0;
    int l = 1, r = n;
    while (l <= r) {
      int m = l + ((r - l) >> 1);
      long coins = m / 2.0 * (m + 1);
      if (coins <= n) {
        l = m + 1;
        row = max(row, m);
      }
      else
        r = m - 1;
    }
    return row;
  }
};