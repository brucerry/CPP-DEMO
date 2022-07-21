// https://leetcode.com/problems/palindrome-number/

// time: O(log(x) base 10)
// space: O(1)

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0 or (x and x % 10 == 0))
      return false;
    
    int reverse_x = 0;
    while (x > reverse_x) {
      reverse_x = reverse_x * 10 + x % 10;
      x /= 10;
    }
    
    return x == reverse_x or x == reverse_x / 10;
  }
};