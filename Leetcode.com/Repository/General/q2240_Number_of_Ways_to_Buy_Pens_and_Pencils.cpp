// https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/

// time: O(total)
// space: O(1)

class Solution {
public:
  long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long ways = 0;
    for (; total >= 0; total -= cost1) {
      ways += total / cost2 + 1;
    }
    return ways;
  }
};