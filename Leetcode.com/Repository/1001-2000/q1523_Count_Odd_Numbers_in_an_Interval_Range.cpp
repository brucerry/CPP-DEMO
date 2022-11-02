// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

// time: O(1)
// space: O(1)

class Solution {
public:
  int countOdds(int low, int high) {
    return (high - low + 1) / 2 + (low % 2 and high % 2);
  }
};