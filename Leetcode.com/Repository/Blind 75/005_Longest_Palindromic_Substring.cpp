// https://leetcode.com/problems/longest-palindromic-substring/

#include <string>
using namespace std;

// time: O(s^2)
// space: O(1)

class Solution {
public:
  string longestPalindrome(string& s) {
    int startIndex = 0, maxLen = 0;
    
    for (int i = 0; i < s.length(); i++) {
      // odd
      int l = i, r = i;
      while (0 <= l and r < s.length() and s[l] == s[r]) {
        if (maxLen < r - l + 1) {
          maxLen = r - l + 1;
          startIndex = l;
        }
        l--;
        r++;
      }
      
      // even
      l = i, r = i + 1;
      while (0 <= l and r < s.length() and s[l] == s[r]) {
        if (maxLen < r - l + 1) {
          maxLen = r - l + 1;
          startIndex = l;
        }
        l--;
        r++;
      }
    }
    
    return s.substr(startIndex, maxLen);
  }
};