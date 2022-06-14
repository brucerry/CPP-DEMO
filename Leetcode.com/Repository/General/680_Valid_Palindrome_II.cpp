// https://leetcode.com/problems/valid-palindrome-ii/

#include <string>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool validPalindrome(string& s) {
    for (int l = 0, r = s.length() - 1; l < r; l++, r--) {
      if (s[l] != s[r])
        return isPalindrome(s, l, r - 1) or isPalindrome(s, l + 1, r);
    }
    return true;
  }
  
private:
  bool isPalindrome(string& s, int l, int r) {
    for (; l < r; l++, r--) {
      if (s[l] != s[r])
        return false;
    }
    return true;
  }
};