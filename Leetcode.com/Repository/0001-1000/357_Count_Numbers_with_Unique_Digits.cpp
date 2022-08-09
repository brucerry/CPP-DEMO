// https://leetcode.com/problems/count-numbers-with-unique-digits/

// time: O(9) => O(1)
// space: O(1)

class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    // n = 0, return 1
    // n = 1, return 10 (0 ... 9)
    // n = 2, return 9*9
    // n = 3, return 9*9*8
    // n = 4, return 9*9*8*7
    
    if (!n)
      return 1;
    
    int total = 10;
    for (int available = 9, unique = 9; n > 1 and available; n--, available--) {
      unique *= available;
      total += unique;
    }
    
    return total;
  }
};