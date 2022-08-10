// https://leetcode.com/problems/integer-replacement/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  int integerReplacement(int n) {
    int op = 0;
    while (n != 1) {
      if (n % 2 == 0)
        n /= 2;
      else if (n == 3 or (n & 3) == 1) {
        n = (n - 1) / 2;
        op++;
      }
      else {
        n = ((unsigned)n + 1) / 2;
        op++;
      }
      
      op++;
    }
    return op;
  }
};