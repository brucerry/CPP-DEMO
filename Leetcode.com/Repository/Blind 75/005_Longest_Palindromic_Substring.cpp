// https://leetcode.com/problems/longest-palindromic-substring/

#include <string>
using namespace std;

// time: O(n^2)
// space: O(1)

class Solution {
public:
  string longestPalindrome(string& s) {
    int startIndex = 0, maxLen = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
      // odd
      int l = i, r = i;
      while (0 <= l and r < n and s[l] == s[r]) {
        if (maxLen < r - l + 1) {
          maxLen = r - l + 1;
          startIndex = l;
        }
        l--;
        r++;
      }
      
      // even
      l = i, r = i + 1;
      while (0 <= l and r < n and s[l] == s[r]) {
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