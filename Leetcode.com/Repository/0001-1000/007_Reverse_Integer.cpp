// https://leetcode.com/problems/reverse-integer/

// time: O(log(x)) There are roughly log{10}(x) digits in x
// space: O(1)

class Solution {
public:
  int reverse(int x) {
    int result = 0;
    
    while (x) {
      int digit = x % 10;
      
      if (result > INT_MAX / 10 or (result == INT_MAX / 10 and digit > INT_MAX % 10))
        return 0;
      
      if (result < INT_MIN / 10 or (result == INT_MIN / 10 and digit < INT_MIN % 10))
        return 0;
      
      result = result * 10 + digit;
      x /= 10;
    }
    
    return result;
  }
};