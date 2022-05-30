// https://leetcode.com/problems/valid-palindrome/

#include <string>
using namespace std;

// time: O(s)
// space: O(1)

class Solution {
public:
  bool isPalindrome(string& s) {
    int l = 0, r = s.length() - 1;
    
    while (l < r) {
      while (l < r and !isalnum(s[l]))
        l++;
      while (l < r and !isalnum(s[r]))
        r--;
      if (tolower(s[l]) != tolower(s[r]))
        return false;
      l++;
      r--;
    }
    
    return true;
  }
};