// https://leetcode.com/problems/smallest-even-multiple/

// time: O(1)
// space: O(1)

class Solution {
public:
  int smallestEvenMultiple(int n) {
    return n % 2 ? n * 2 : n;
  }
};