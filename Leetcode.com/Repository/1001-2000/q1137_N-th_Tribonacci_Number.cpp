// https://leetcode.com/problems/n-th-tribonacci-number/

// time: O(n)
// space: O(1)

class Solution {
public:
  int tribonacci(int n) {
    if (n < 2)
      return n;
    
    int one = 0, two = 1, three = 1;
    for (int i = 2; i < n; i++) {
      int tmp = one + two + three;
      one = two;
      two = three;
      three = tmp;
    }
    
    return three;
  }
};