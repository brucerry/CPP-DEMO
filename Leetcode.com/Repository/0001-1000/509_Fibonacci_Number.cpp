// https://leetcode.com/problems/fibonacci-number/

// time: O(n)
// space: O(1)

class Solution {
public:
  int fib(int n) {
    if (n < 2)
      return n;
    
    int one = 0, two = 1;
    for (int i = 2; i <= n; i++) {
      int tmp = one + two;
      one = two;
      two = tmp;
    }
    return two;
  }
};