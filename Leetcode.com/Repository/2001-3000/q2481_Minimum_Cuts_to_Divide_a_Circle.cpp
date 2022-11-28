// https://leetcode.com/problems/minimum-cuts-to-divide-a-circle/

// time: O(1)
// space: O(1)

class Solution {
public:
  int numberOfCuts(int n) {
    if (n == 1)
      return 0;
    return n % 2 ? n : n / 2;
  }
};