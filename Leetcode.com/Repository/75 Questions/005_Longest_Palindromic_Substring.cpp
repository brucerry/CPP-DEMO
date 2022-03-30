// https://leetcode.com/problems/longest-palindromic-substring/

#include <string>
using namespace std;

// time: O(s^2)
// space: O(1)

class Solution {
public:
  string longestPalindrome(string s) {
    int maxLen = 1;
    int startIndex = 0;
    
    // odd len
    for (int i = 0; i < s.length(); i++) {
      int l = i, r = i;
      while (l >= 0 && r < s.length() && s[l] == s[r]) {
        int len = r - l + 1;
        if (maxLen < len) {
          maxLen = len;
          startIndex = l;
        }
        l--;
        r++;
      }
    }
    
    // even len
    for (int i = 0; i < s.length(); i++) {
      int l = i, r = i + 1;
      while (l >= 0 && r < s.length() && s[l] == s[r]) {
        int len = r - l + 1;
        if (maxLen < len) {
          maxLen = len;
          startIndex = l;
        }
        l--;
        r++;
      }
    }
    
    return s.substr(startIndex, maxLen);
  }
};